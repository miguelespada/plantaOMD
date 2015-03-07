//
//  soap.cpp
//  planta
//
//  Created by miguel on 07/03/15.
//
//

#include "Soap.h"
#include "SoapEvent.h"
#include "Settings.h"

Soap::Soap(){
    ofAddListener(ofEvents().update, this, &Soap::update);
}

void Soap::update(ofEventArgs &args){
    if(json == NULL)
        ofSendMessage("[Info] SOAP NOT available");
    else
        ofSendMessage("[Info] SOAP available");
    
    if(json == NULL || ofGetFrameNum() % (60 * Settings::getInstance()->getSoapRefreshRate()) == 0){
        fetchData();
        
        for(int i = 0; i < 4; i ++){
            SoapEvent event(i, json["d"][i]["Value"].asInt());
            ofNotifyEvent(SoapEvent::SoapEvents, event);
        }
    }
}

int Soap::getValue(int index){
    return json["d"][index]["Value"].asInt();
}

void Soap::fetchData(){    
    string response = ofSystem("curl --header \"Content-Type: application/json;charset=UTF-8\" \
                               --header \"SOAPAction:GetKPIs\" \
                               --data \"\" \
                               http://www.omd.es/wstimereport/wscontrol.asmx/GetKPIs ");
    json.parse(response);
    
}
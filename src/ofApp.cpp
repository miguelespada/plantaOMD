#include "ofApp.h"
#include "Settings.h"
#include "General.h"

#include "ofxJSON.h"

ofApp::ofApp(){
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    app.setCurrentState(new General(&app));
 
    string response = ofSystem("curl --header \"Content-Type: application/json;charset=UTF-8\" --header \"SOAPAction:GetKPIs\" --data \"\" http://www.omd.es/wstimereport/wscontrol.asmx/GetKPIs ");
    ofxJSONElement json;
    json.parse(response);
    cout << json["d"][0]["Value"].asInt() << endl;
    cout << json["d"][1]["Value"].asInt() << endl;
    cout << json["d"][2]["Value"].asInt() << endl;
    cout << json["d"][3]["Value"].asInt() << endl;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // Services are updated with listeners
}

//--------------------------------------------------------------
void ofApp::draw(){
    app.draw();
    info.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'F':
            ofToggleFullscreen();
            break;
        case 'c':
            ofHideCursor();
            break;
        case 'C':
            ofShowCursor();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){}
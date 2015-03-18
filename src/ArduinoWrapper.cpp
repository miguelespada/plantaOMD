//
//  ArduinoWrapper.cpp
//  planta
//
//  Created by miguel on 21/02/15.
//
//

#include "ArduinoWrapper.h"

ArduinoWrapper::ArduinoWrapper(){
    bArduinoConnected = false;
    bSetupArduino = false;
    arduino = new ofSerial;
    ofAddListener(ofEvents().update, this, &ArduinoWrapper::update);
    ofAddListener(ofEvents().keyPressed, this, &ArduinoWrapper::keyPressed);

}

ArduinoWrapper::~ArduinoWrapper(){
    if(bArduinoConnected){
        arduino->close();
        delete arduino;
    }
}

string ArduinoWrapper::getPort(){
    ofSerial serial;
    vector <ofSerialDeviceInfo> deviceList =  serial.getDeviceList();
    for (int i=0; i<deviceList.size(); i++) {
        if(deviceList[i].getDeviceName().find("tty.usbmodem") != std::string::npos){
            return deviceList[i].getDeviceName();
        }
    }
    return "";
};

void ArduinoWrapper::connectArduino(string deviceName){
    bArduinoConnected = arduino->setup(deviceName, 9600);
}

//--------------------------------------------------------------
void ArduinoWrapper::update(){
    if(bArduinoConnected) {
        ofSendMessage("[Info] Arduino connected");
        read();
    }
    else{
        ofSendMessage("[Info] Arduino NOT connected");
    }
    
    if(ofGetFrameNum() % 90 == 0){
        string deviceName = getPort();
        if(deviceName == "" && bArduinoConnected){
            arduino->close();
            bArduinoConnected = false;
        }
        if(deviceName != "" && !bArduinoConnected){
            connectArduino(deviceName);
        }
    }
}

//--------------------------------------------------------------
void ArduinoWrapper::update(ofEventArgs &args){
    update();
}

//--------------------------------------------------------------
void ArduinoWrapper::read(){
    if ( arduino->available() > 0 )
    {
        int myByte = 0;
        
        myByte = arduino->readByte();
        if ( myByte == OF_SERIAL_NO_DATA ){
            
        }
        else if ( myByte == OF_SERIAL_ERROR ){
            ofLogError() << "Error reading Arduino";
        }
        else{
            if(char(myByte) == '\n' ){
                processData();
                data.clear();
            }
            else{
                data += char(myByte);
            }
        }
    }
}

void ArduinoWrapper::processData(){
    ofLogNotice() << "RECEIVED: " << data;
    vector <string> tokens = ofSplitString(data, ",");
    
    ArduinoEvent event("Temperature", ofToInt(tokens[0]));
    ofNotifyEvent(ArduinoEvent::digitalEvents, event);
    
    ArduinoEvent event2("Humidity", ofToInt(tokens[1]));
    ofNotifyEvent(ArduinoEvent::digitalEvents, event2);
    
}

//--------------------------------------------------------------
void ArduinoWrapper::write(){
    arduino->writeByte(1);
}


void ArduinoWrapper::keyPressed (ofKeyEventArgs& eventArgs){
    switch (eventArgs.key) {
        case '1':
            arduino->writeByte(13);
            arduino->writeByte(1);
            ofLogNotice() << "ON 13";
            break;
        case '2':
            arduino->writeByte(13);
            arduino->writeByte(0);
            ofLogNotice() << "OFF 13";
            break;
    }
}



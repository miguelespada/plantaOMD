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
    ofRegisterGetMessages(this);
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


void ArduinoWrapper::gotMessage(ofMessage& msg){
    if(msg.message.substr(0, 9) == "[Arduino]"){
        if(msg.message == "[Arduino] increment"){
            randomLight();
        }
        else{
            vector<string> tokens = ofSplitString(msg.message.substr(9), ";");
            ofLogNotice() << "[ArduinoWrapper] Received: " << tokens[0] << " " <<  tokens[1];
            if(tokens[0] == "luz"){
                randomLight();
            }
            if(tokens[0] == "agua"){
                arduino->writeByte(2);
                arduino->writeByte(ofToInt(tokens[1]));
                ofLogNotice() << "[Set pin] " << 2 << " " << tokens[1];
            }
            if(tokens[0] == "niebla"){
                arduino->writeByte(3);
                arduino->writeByte(ofToInt(tokens[1]));
                arduino->writeByte(4);
                arduino->writeByte(ofToInt(tokens[1]));
                ofLogNotice() << "[Set pin] " << 3 << " " <<  4 << " " << tokens[1];
            }
            if(tokens[0] == "viento"){
                arduino->writeByte(5);
                arduino->writeByte(ofToInt(tokens[1]));
                ofLogNotice() << "[Set pin] " << 5 << " " << tokens[1];
        }
        }
    }
}

void ArduinoWrapper::randomLight(){
    int r = ofRandom(255);
    int g = ofRandom(255);
    int b = ofRandom(255);
    arduino->writeByte(6);
    arduino->writeByte(r);
    arduino->writeByte(g);
    arduino->writeByte(b);
    ofLogNotice() << "[Set light] " << r << " " << g << " " << b;
}

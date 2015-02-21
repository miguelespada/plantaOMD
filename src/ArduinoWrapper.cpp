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

    arduino = new ofArduino;
    ofAddListener(ofEvents().update, this, &ArduinoWrapper::update);
}

ArduinoWrapper::~ArduinoWrapper(){
    if(bArduinoConnected){
        arduino->disconnect();
        delete arduino;
    }
}

string ArduinoWrapper::getPort(){
    ofSerial serial;
    vector <ofSerialDeviceInfo> deviceList =  serial.getDeviceList();
    for (int i=0; i<deviceList.size(); i++) {
        if(deviceList[i].getDeviceName().find("tty.usbmodem") != std::string::npos){
            ofLogNotice() << "Found Arduino: " << deviceList[i].getDeviceName();
            return deviceList[i].getDeviceName();
        }
    }
    ofLogNotice() << "Arduino NOT found ";
    return "";
};

void ArduinoWrapper::connectArduino(string deviceName){
    bArduinoConnected = arduino->connect(deviceName, 57600);
    ofAddListener(arduino->EInitialized, this, &ArduinoWrapper::setupArduino);
    bSetupArduino= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
}

//--------------------------------------------------------------
void ArduinoWrapper::setupArduino(const int & version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino->EInitialized, this, &ArduinoWrapper::setupArduino);
    
    // it is now safe to send commands to the Arduino
    bSetupArduino = true;
    
    // print firmware name and version to the console
    ofLogNotice() << arduino->getFirmwareName();
    ofLogNotice() << "firmata v" << arduino->getMajorFirmwareVersion() << "." << arduino->getMinorFirmwareVersion();
    
    configPins();
    
    // Listen for changes on the digital and analog pins
    ofAddListener(arduino->EDigitalPinChanged, this, &ArduinoWrapper::digitalPinChanged);
}

//--------------------------------------------------------------
void ArduinoWrapper::configPins(){
    for(int i = 0; i < 4; i ++){
        arduino->sendDigitalPinMode(i + 2, ARD_INPUT);
        arduino->sendDigital(i  + 2 , ARD_HIGH);
    }
    arduino->sendDigitalPinMode(6, ARD_INPUT);
}


//--------------------------------------------------------------
void ArduinoWrapper::update(){
    
    if(bArduinoConnected)
        arduino->update();
    
    if(ofGetFrameNum() % RECONNECT_RATE == 0){
        string deviceName = getPort();
        
        if(deviceName == ""){
            if(bArduinoConnected){
                arduino->disconnect();
                bArduinoConnected = false;
            }
        }
        else {
            connectArduino(deviceName);
        }
    }
}

//--------------------------------------------------------------
void ArduinoWrapper::update(ofEventArgs &args){
    update();
}

//--------------------------------------------------------------
void  ArduinoWrapper::digitalPinChanged(const int & pinNum) {
}


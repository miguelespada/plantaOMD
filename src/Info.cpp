//
//  Info.cpp
//  planta
//
//  Created by miguel on 20/02/15.
//
//

#include "Info.h"

Info::Info(){
    ofAddListener(ofEvents().keyPressed, this, &Info::keyPressed);
    ofRegisterGetMessages(this);
    ss = "";
};


void Info::draw(){
    if(!bInfo) return;
    ofPushStyle();
    
    ofSetColor(255);
    ofLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());
    ofLine(0, ofGetMouseY(), ofGetWidth(), ofGetMouseY());
    ofDrawBitmapString(ofToString(ofGetMouseX()) + ", " + ofToString(ofGetMouseY()), ofGetMouseX() + 5, ofGetMouseY() + 15);
    ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()), 5, 15);
    ofDrawBitmapString(ss, 5, 30);
    ss = "";
    ofPopStyle();
};

void Info::toggle(){
    bInfo = !bInfo;
};

void Info::keyPressed (ofKeyEventArgs& eventArgs){
    switch (eventArgs.key) {
        case 'i':
            toggle();
            break;
        default:
            break;
    }
}

void Info::gotMessage(ofMessage& msg){
    if(!bInfo) return;
    if(msg.message.substr(0, 6) == "[Info]"){
        ss += msg.message.substr(7);
        ss += "\n";
    }
}
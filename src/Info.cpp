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
};

Info::~Info(){};

void Info::draw(){
    if(!bInfo) return;
    ofPushStyle();
    ofSetColor(255);
    ofLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());
    ofLine(0, ofGetMouseY(), ofGetWidth(), ofGetMouseY());
    ofDrawBitmapString(ofToString(ofGetMouseX()) + ", " + ofToString(ofGetMouseY()), ofGetMouseX() + 5, ofGetMouseY() + 15);
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
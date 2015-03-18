#include "ofApp.h"
#include "Settings.h"
#include "General.h"

#include "ofxJSON.h"
#include "Soap.h"

ofApp::ofApp(){
}

//--------------------------------------------------------------
void ofApp::setup(){
//    ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    ofSetWindowShape(Settings::getInstance()->getHeight(), Settings::getInstance()->getWidth());

    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    app.setCurrentState(new General(&app));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // Services are updated with listeners
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
//    ofTranslate(ofGetWidth(), 0);
//    ofRotate(90);
    app.draw();
    ofPopMatrix();
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

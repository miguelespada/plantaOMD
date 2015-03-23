#include "ofApp.h"
#include "Settings.h"
#include "General.h"

#include "ofxJSON.h"
#include "Soap.h"

ofApp::ofApp(){
}

//--------------------------------------------------------------
void ofApp::setup(){
    
    setRotation();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    app.setCurrentState(new General(&app));
    ofToggleFullscreen();
    ofHideCursor();
    
}

//--------------------------------------------------------------
void ofApp::update(){
    // Services are updated with listeners
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    if(bRotated){
        ofTranslate(ofGetWidth(), 0);
        ofRotate(90);
    }
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
        case 'R':
            bRotated = !bRotated;
            setRotation();
            break;
        default:
            break;
    }
}


void ofApp::setRotation(){
    
    if(bRotated)
        ofSetWindowShape(Settings::getInstance()->getHeight(), Settings::getInstance()->getWidth());
    else
        ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    
}
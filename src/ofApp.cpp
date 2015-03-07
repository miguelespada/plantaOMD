#include "ofApp.h"
#include "Idle.h"
#include "Settings.h"

ofApp::ofApp(){
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    
    app.setCurrentState(new IDLE(&app));
    
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
        case 'f':
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
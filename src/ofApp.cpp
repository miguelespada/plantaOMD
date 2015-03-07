#include "ofApp.h"
#include "Settings.h"
#include "Luz.h"

ofApp::ofApp(){
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
    
    app.setCurrentState(new Luz::Luz(&app));
    
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
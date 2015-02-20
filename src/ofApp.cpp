#include "ofApp.h"
#include "Idle.h"
#include "Settings.h"
#include "Settings.h"

ofApp::ofApp(){
    ofLogVerbose() << "Constructing Main";
}

ofApp::~ofApp(){
    ofLogVerbose() << "Destroying Main";
}

//--------------------------------------------------------------
void ofApp::setup(){

    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
   
    app.setCurrent(new IDLE(&app));
    
    ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    app.update();
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
        case 'n':
            app.next();
            break;
        case 'c':
            ofHideCursor();
            break;
        case 'C':
            ofShowCursor();
            break;
        case 'i':
            info.toggle();
            break;
        default:
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){}
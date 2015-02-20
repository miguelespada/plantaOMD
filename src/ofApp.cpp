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

    ofSetWindowPosition(0, 0);
   
    app.setCurrent(new IDLE(&app));

    ofEnableAlphaBlending();
    
    ofSetWindowShape(Settings::getInstance()->getWidth(), Settings::getInstance()->getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    app.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
        ofPushMatrix();
        app.draw();
        ofPopMatrix();
    ofPopStyle();
    
    ofPushStyle();
    if(bInfo){
        ofSetColor(255);
        ofLine(ofGetMouseX(), 0, ofGetMouseX(), ofGetHeight());
        ofLine(0, ofGetMouseY(), ofGetWidth(), ofGetMouseY());
        ofDrawBitmapString(ofToString(ofGetMouseX()) + ", " + ofToString(ofGetMouseY()), ofGetMouseX() + 5, ofGetMouseY() + 15);
    }
    ofPopStyle();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case 'f':
            ofToggleFullscreen();
            break;
        case 'j':
            app.jump();
            break;
        case 'c':
            ofHideCursor();
            break;
        case 'C':
            ofShowCursor();
            break;
        case 'i':
            bInfo = !bInfo;
            break;
        default:
            break;
    }
}

void ofApp::keyReleased(int key){
}

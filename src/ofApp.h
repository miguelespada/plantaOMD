#pragma once

#include "ofMain.h"
#include "App.h"
#include "Info.h"
#include "Soap.h"

class ofApp : public ofBaseApp{
public:
    ofApp();

    void setup();
    void update();
    void draw();

    void keyPressed(int key);

    App app;
    Info info;
    Soap soap;
};



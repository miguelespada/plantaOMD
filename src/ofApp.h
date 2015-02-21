#pragma once

#include "ofMain.h"
#include "App.h"
#include "Info.h"

class ofApp : public ofBaseApp{
public:
    ofApp();

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    App app;
    Info info;
};



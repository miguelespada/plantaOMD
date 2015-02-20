#pragma once

#include "ofMain.h"
#include "App.h"
#include "Info.h"
#include "Assets.h"

class ofApp : public ofBaseApp{
public:
    ~ofApp();
    ofApp();

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);

    App app;
    Info info;
};



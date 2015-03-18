//
//  State.h
//  Game
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __game__State__
#define __game__State__

#include "ofMain.h"
#include "Settings.h"
#include "Assets.h"

class App;

class State
{
public:
    App *app;
    Assets *assets = Assets::getInstance();
    
    
    float timer;
    virtual void next()=0;
    virtual void jump(){};
    virtual std::string toString() {};
    virtual void draw() {};
    virtual void update() {};
    
    void drawValue(string s, int y){
        ofPushMatrix();
        
        int w = assets->fontPlainSmall.stringWidth(s);
        int h = assets->fontPlainSmall.stringHeight(s);
        
        ofSetColor(Settings::getInstance()->getBackgroundColor());
        
        ofRect(ofGetWidth() - 200, ofGetHeight() - 80, 200, 80);
        
        ofTranslate(ofGetWidth() - w - 20, y);
        
        ofNoFill();
        
        ofSetColor(Settings::getInstance()->getGrayColor());
        
        ofRect(-5, -h - 5, w + 10,  h * 2);
        
        Assets::getInstance()->drawString(s, 0, 0, assets->fontPlainSmall);
        ofPopMatrix();
    }
  
};


#endif

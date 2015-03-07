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
};


#endif

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
#include "Action.h"

//========================================================================

class App;

class State
{
public:
    App *app;
    float timer;
    virtual void push() =0;
    virtual void jump() {};
    virtual std::string toString() {}
    virtual void draw() {}
    virtual void update() {};
    virtual void notify(Action *action) {}
};


#endif /* defined(__planta__Idle__) */

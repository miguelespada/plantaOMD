#ifndef App_App_h
#define App_App_h
#pragma once

#include "ofMain.h"
#include "State.h"
#include "ArduinoEvent.h"
#include "ArduinoWrapper.h"

class App
{
    
public:
    App();    
    class State *current_state;
    
    void setCurrentState(State *s);
    void keyPressed(ofKeyEventArgs& eventArgs);
    void update(ofEventArgs &args);
    
    void update();
    void next();
    void jump();
    void draw();
    
    ArduinoWrapper arduino;
    void arduinoEvent(ArduinoEvent &e);
};

#endif

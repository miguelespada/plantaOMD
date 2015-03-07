#ifndef App_App_h
#define App_App_h
#pragma once

#include "ofMain.h"
#include "State.h"
#include "ArduinoEvent.h"
#include "ArduinoWrapper.h"

#define MAL 0
#define REGULAR 1
#define BIEN 2

#define LUZ 0
#define NIEBLA 1
#define AGUA 2
#define VIENTO 3


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
    int getState(int state);
    
    ArduinoWrapper arduino;
    void arduinoEvent(ArduinoEvent &e);
    
    int states[4];
};

#endif

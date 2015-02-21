#ifndef App_App_h
#define App_App_h

#include "ofMain.h"
#include "State.h"
#include "ArduinoEvent.h"

class App
{
    
public:
    App();    
    ~App();
    class State *current_state;
    
    void setCurrentState(State *s);
    void keyPressed(ofKeyEventArgs& eventArgs);
    void update(ofEventArgs &args);
    
    void update();
    void next();
    void jump();
    void draw();
    
    void arduinoEvent(ArduinoEvent &e);
};

#endif

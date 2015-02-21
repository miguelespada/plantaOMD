#ifndef App_App_h
#define App_App_h

#include "ofMain.h"
#include "Observer.h"
#include "Commandable.h"
#include "State.h"
#include "Action.h"

class App: public Observer, public Commandable
{
    
public:
    App();    
    ~App();
    class State *current_state;
    
    void setCurrentState(State *s);
    void notify(Action *action);
    void keyPressed(ofKeyEventArgs& eventArgs);
    void update(ofEventArgs &args);
    
    void update();
    void next();
    void jump();
    void draw();
};

#endif

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
    class Settings *settings;
    
    void setCurrent(State *s);
    void notify(Action *action);
    
    void next();
    void jump();
    void draw();
    void update();
};

#endif

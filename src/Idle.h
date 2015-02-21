#ifndef __planta__Idle__
#define __planta__Idle__

#include <State.h>
//========================================================================

class IDLE: public State{
public:
    IDLE(App *g);
    std::string toString() { return "Idle"; }
    void update();
    void draw();
    void next();
};


#endif /* defined(__planta__Idle__) */

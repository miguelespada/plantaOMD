#ifndef __planta__Luz_state__
#define __planta__Luz_state__

#include <State.h>

class Luz: public State
{
public:
    Luz(App *g);
    std::string toString() { return "Luz"; }
    void update();
    void draw();
    void next();
};

#endif /* defined(__planta__Luz_state__) */

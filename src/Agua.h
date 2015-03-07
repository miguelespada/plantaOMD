#ifndef __planta__Agua_state__
#define __planta__Agua_state__

#include <State.h>

class Agua: public State
{
public:
    Agua(App *g);
    std::string toString() { return "Agua"; }
    void update();
    void draw();
    void next();
};

#endif /* defined(__planta__Agua_state__) */

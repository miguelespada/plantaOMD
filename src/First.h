#ifndef __planta__First_state__
#define __planta__First_state__

#include <State.h>

class First: public State
{
public:
    First(App *g);
    std::string toString() { return "First"; }
    void update();
    void draw();
    void next();
};

#endif /* defined(__planta__First_state__) */

#ifndef __planta__Viento_state__
#define __planta__Viento_state__

#include <State.h>

class Viento: public State
{
public:
    Viento(App *g);
    std::string toString() { return "Viento"; }
    void update();
    void draw();
    void next();
};

#endif /* defined(__planta__Viento_state__) */

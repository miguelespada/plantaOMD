#ifndef __planta__Niebla_state__
#define __planta__Niebla_state__

#include <State.h>

class Niebla: public State
{
public:
    Niebla(App *g);
    std::string toString() { return "Niebla"; }
    void update();
    void draw();
    void next();
};

#endif /* defined(__planta__Niebla_state__) */

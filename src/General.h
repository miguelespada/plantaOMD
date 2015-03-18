#ifndef __planta__General__
#define __planta__General__

#include <State.h>
//========================================================================

class General: public State{
    void drawElement(string element, int amount, int x, int y, ofColor color);

public:
    General(App *g);
    std::string toString() { return "General"; }
    void update();
    void draw();
    void next();

};


#endif /* defined(__planta__General__) */

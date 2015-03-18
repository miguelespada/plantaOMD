

#ifndef __planta__AnimationFlor__
#define __planta__AnimationFlor__

#include "Animation.h"

class AnimationFlor: public Animation{
    int h = 0;
public:
    AnimationFlor(string path, int n);
    void draw();
};

#endif /* defined(__planta__AnimationAguaMal__) */

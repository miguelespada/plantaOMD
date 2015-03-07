//
//  AnimationAguaMal.h
//  planta
//
//  Created by miguel on 07/03/15.
//
//

#ifndef __planta__AnimationAguaMal__
#define __planta__AnimationAguaMal__

#include "Animation.h"

class AnimationAguaMal: public Animation{
public:
    AnimationAguaMal(string path, int n);
    void draw();
};

#endif /* defined(__planta__AnimationAguaMal__) */

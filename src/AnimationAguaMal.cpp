//
//  AnimationAguaMal.cpp
//  planta
//
//  Created by miguel on 07/03/15.
//
//

#include "AnimationAguaMal.h"

#include "Settings.h"
#include "Assets.h"

AnimationAguaMal::AnimationAguaMal(string path, int max)
:Animation(path, max){
}

void AnimationAguaMal::draw(){
    if(index == 0)
        draw_background();
    else
        images[index + 1].draw(0,0);
}

//
//  AnimationAguaMal.cpp
//  planta
//
//  Created by miguel on 07/03/15.
//
//

#include "AnimationFlor.h"

#include "Settings.h"
#include "Assets.h"

AnimationFlor::AnimationFlor(string path, int max)
:Animation(path, max){
}

void AnimationFlor::draw(){
    images[1].draw(0,0);
    
    for(int i = 0; i < h; i ++){
        images[2].draw(0,-8 * i);
    }
    
    if(ofGetFrameNum() % (Settings::getInstance()->getAnimationRate() * 4) == 0){
        h = ofRandom(9);
    }
    
}

//
//  Animation.cpp
//  planta
//
//  Created by miguel on 07/03/15.
//
//

#include "Animation.h"
#include "Settings.h"
#include "Assets.h"

Animation::Animation(string path, int max){
    Animation::max = max;
    Animation::path = path;
    Animation::index = 0;
    Animation::images = new ofImage[max];
    loadImages();
}

void Animation::draw_background(){
    images[0].draw(0,0);
}

void Animation::draw(){
    draw_background();
    images[index + 1].draw(0,0);
}

void Animation::update(){
    if(ofGetFrameNum() % Settings::getInstance()->getAnimationRate() == 0)
        index = (index + 1) % (max - 1);
}

void Animation::loadImages(){
    for(int i = 0; i < max; i ++){
         Assets::getInstance()->loadImage(path + ofToString(i) + ".png", images[i]);
    }
}

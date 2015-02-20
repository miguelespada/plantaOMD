//
//  Idle.cpp
//  planta
//
//  Created by miguel on 20/02/15.
//
//

#include "Idle.h"
#include "Settings.h"

//========================================================================

IDLE::IDLE(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void IDLE::notify(Action *action){
};

void IDLE::draw(){
    ofBackground(Settings::getInstance()->getBackgroundColor());
};

void IDLE::update(){
}

void IDLE::push(){
    delete this;
};



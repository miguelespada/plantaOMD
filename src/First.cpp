//
//  First_state.cpp
//  planta
//
//  Created by miguel on 20/02/15.
//
//

#include "First.h"
#include "App.h"
#include "Idle.h"

//========================================================================


First::First(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void First::notify(Action *action){
};

void First::draw(){
    ofBackground(0);
};

void First::update(){
}

void First::push(){};

void First::jump(){
    
    app->setCurrent(new IDLE(app));
    delete this;
};
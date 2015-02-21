#include "First.h"
#include "App.h"
#include "Idle.h"

First::First(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void First::draw(){
    ofBackground(0);
};

void First::update(){}

void First::next(){
    app->setCurrentState(new IDLE(app));
    delete this;
};
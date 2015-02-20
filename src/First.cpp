#include "First.h"
#include "App.h"
#include "Idle.h"

First::First(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void First::notify(Action *action){};

void First::draw(){
    ofBackground(0);
};

void First::update(){}

void First::next(){
    app->setCurrent(new IDLE(app));
    delete this;
};
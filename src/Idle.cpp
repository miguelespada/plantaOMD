#include "Idle.h"
#include "First.h"
#include "App.h"

IDLE::IDLE(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void IDLE::draw(){
    ofBackground(Settings::getInstance()->getBackgroundColor());
};

void IDLE::update(){
}

void IDLE::next(){
    app->setCurrentState(new First(app));
    delete this;
};
#include "Luz.h"
#include "App.h"
#include "General.h"

Luz::Luz(App *a){
    app = a;
    ofLogNotice() << "State: " << toString();
};

void Luz::draw(){
    ofBackground(Settings::getInstance()->getBackgroundColor());
};

void Luz::update(){}

void Luz::next(){
    app->setCurrentState(new General(app));
    delete this;
};
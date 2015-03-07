#include "Luz.h"
#include "App.h"
#include "General.h"

Luz::Luz(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
};

void Luz::draw(){
    ofBackground(Settings::getInstance()->getBackgroundColor());
    assets->luz_mal->draw();
};

void Luz::update(){
    assets->luz_mal->update();
}

void Luz::next(){
    app->setCurrentState(new General(app));
    delete this;
};
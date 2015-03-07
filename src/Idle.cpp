#include "Idle.h"
#include "First.h"
#include "App.h"

IDLE::IDLE(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
    assets = Assets::getInstance();
};

void IDLE::draw(){
    ofBackground(Settings::getInstance()->getBackgroundColor());
    
    assets->planta.draw(0,0);
    assets->viento->draw();
    assets->niebla->draw();
    assets->luz->draw();
    assets->agua->draw();
};

void IDLE::update(){
    assets->viento->update();
    assets->niebla->update();
    assets->luz->update();
    assets->agua->update();
}

void IDLE::next(){
    app->setCurrentState(new First(app));
    delete this;
};
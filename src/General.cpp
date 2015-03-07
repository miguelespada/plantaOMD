#include "General.h"
#include "Luz.h"
#include "App.h"

General::General(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
    assets = Assets::getInstance();
};

void General::draw(){
    ofBackground(Settings::getInstance()->getBackgroundColor());
    
    assets->planta.draw(0,0);
    assets->viento->draw();
    assets->niebla->draw();
    assets->luz->draw();
    assets->agua->draw();
};

void General::update(){
    assets->viento->update();
    assets->niebla->update();
    assets->luz->update();
    assets->agua->update();
}

void General::next(){
    app->setCurrentState(new Luz(app));
    delete this;
};
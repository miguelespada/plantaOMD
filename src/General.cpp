#include "General.h"
#include "Luz.h"
#include "App.h"

General::General(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
};

void General::draw(){
    ofBackground(Settings::getInstance()->getBackgroundColor());
    
    assets->planta.draw(0,0);
    assets->viento->draw();
    assets->niebla->draw();
    assets->luz->draw();
    assets->agua->draw();
    assets->flor->draw();
    
    assets->drawString("TEMPERATURA:20º", 330, 746);
    assets->drawString("HUMEDAD:82%", 360, 776);
};

void General::update(){
    assets->viento->update();
    assets->niebla->update();
    assets->luz->update();
    assets->agua->update();
    assets->flor->update();
}

void General::next(){
    app->setCurrentState(new Luz(app));
    delete this;
};
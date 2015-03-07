#include "Luz.h"
#include "App.h"
#include "Viento.h"

Luz::Luz(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
};

void Luz::draw(){
    ofBackground(Settings::getInstance()->getBackgroundColor());
    switch (app->getState(LUZ)) {
        case BIEN:
            assets->luz_bien->draw();
            break;
        case MAL:
            assets->luz_mal->draw();
            break;
        case REGULAR:
            assets->luz_regular->draw();
            break;
        default:
            break;
    }
    
    assets->drawString("LUZ:" + ofToString(app->getSoapValue(LUZ)), 380, 776);
};

void Luz::update(){
    
    assets->luz_bien->update();
    assets->luz_regular->update();
    assets->luz_mal->update();
}

void Luz::next(){
    app->setCurrentState(new Viento(app));
    delete this;
};
#include "Viento.h"
#include "App.h"
#include "Niebla.h"

Viento::Viento(App *a){
    ofLogNotice() << "State: " << toString();
    timer = ofGetElapsedTimeMillis();
    app = a;
};

void Viento::draw(){
    switch (app->getPlantState(VIENTO)) {
        case BIEN:
            assets->viento_bien->draw();
            break;
        case MAL:
            assets->viento_mal->draw();
            break;
        case REGULAR:
            assets->viento_regular->draw();
            break;
        default:
            break;
    }
    
    
    drawValue("VIENTO:" + ofToString(app->getPlantValue(VIENTO)) + "%", 775);
    

};

void Viento::update(){
    assets->viento_bien->update();
    assets->viento_regular->update();
    assets->viento_mal->update();
    
    
    if((ofGetElapsedTimeMillis() - timer) > Settings::getInstance()->getStateTime()){
        next();
    }
}

void Viento::next(){
    app->setCurrentState(new Niebla(app));
    delete this;
};
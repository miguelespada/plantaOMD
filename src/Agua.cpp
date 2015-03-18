#include "Agua.h"
#include "App.h"
#include "General.h"

Agua::Agua(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
};

void Agua::draw(){
    switch (app->getPlantState(AGUA)) {
        case BIEN:
            assets->agua_bien->draw();
            break;
        case MAL:
            assets->agua_mal->draw();
            break;
        case REGULAR:
            assets->agua_regular->draw();
            break;
        default:
            break;
    }
    
    drawValue("NUTRIENTES:" + ofToString(app->getPlantValue(AGUA)) + "%", 775);
};

void Agua::update(){
    
    assets->agua_bien->update();
    assets->agua_regular->update();
    assets->agua_mal->update();
}

void Agua::next(){
    app->setCurrentState(new General(app));
    delete this;
};
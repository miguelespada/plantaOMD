#include "Luz.h"
#include "App.h"
#include "Viento.h"

Luz::Luz(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
};

void Luz::draw(){
    switch (app->getPlantState(LUZ)) {
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
    
    
    drawValue("LUZ:" + ofToString(app->getPlantValue(LUZ)) + "%", 775);
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
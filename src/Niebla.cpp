#include "Niebla.h"
#include "App.h"
#include "Agua.h"

Niebla::Niebla(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
};

void Niebla::draw(){
    switch (app->getPlantState(NIEBLA)) {
        case BIEN:
            assets->niebla_bien->draw();
            break;
        case MAL:
            assets->niebla_mal->draw();
            break;
        case REGULAR:
            assets->niebla_regular->draw();
            break;
        default:
            break;
    }
    assets->drawString("NIEBLA:" + ofToString(app->getPlantValue(NIEBLA)), 380, 776, assets->fontPlainSmall);
};

void Niebla::update(){
    assets->niebla_bien->update();
    assets->niebla_regular->update();
    assets->niebla_mal->update();
}

void Niebla::next(){
    app->setCurrentState(new Agua(app));
    delete this;
};
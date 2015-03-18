#include "General.h"
#include "Luz.h"
#include "App.h"

General::General(App *a){
    ofLogNotice() << "State: " << toString();
    app = a;
};

void General::draw(){
    assets->planta.draw(0,0);
    assets->viento->draw();
    assets->niebla->draw();
    assets->luz->draw();
    assets->agua->draw();
    assets->flor->draw();
    
    ofSetColor(Settings::getInstance()->getGrayColor());
    assets->drawString("TEMPERATURA:" + ofToString(app->getTemperature())  + "º", 330, 746, assets->fontPlainSmall);
    assets->drawString("HUMEDAD:" + ofToString(app->getHumidity())  + "%", 360, 776, assets->fontPlainSmall);
    
    drawElement("HUMEDAD", app->getPlantValue(NIEBLA), 222, 675, Settings::getInstance()->getWhiteColor());
    drawElement("NUTRIENTES", app->getPlantValue(AGUA), 8, 528, Settings::getInstance()->getCyanColor());
    drawElement("VIENTO", app->getPlantValue(VIENTO), 30, 170, Settings::getInstance()->getMagentaColor());
    drawElement("LUZ", app->getPlantValue(LUZ), 390, 188, Settings::getInstance()->getYellowColor());
    
};

void General::drawElement(string element, int amount, int x, int y,  ofColor color){
    ofPushMatrix();
    ofSetColor(color);
    ofTranslate(x, y);
    string s = ofToString(amount) + "%";
    assets->drawString(s, 2, 0, assets->fontLight);
    assets->drawString(element, 4, 20, assets->fontPlainMedium);
    ofPopMatrix();
}

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
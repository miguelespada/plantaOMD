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
    assets->drawString("TEMPERATURA:20º", 330, 746, assets->fontPlainSmall);
    assets->drawString("HUMEDAD:82%", 362, 776, assets->fontPlainSmall);
    
    drawElement("NIEBLA", app->getPlantValue(NIEBLA), 222, 675, Settings::getInstance()->getWhiteColor());
    drawElement("AGUA", app->getPlantValue(AGUA), 40, 528, Settings::getInstance()->getCyanColor(), false);
    drawElement("VIENTO", app->getPlantValue(VIENTO), 30, 170, Settings::getInstance()->getMagentaColor());
    drawElement("LUZ", app->getPlantValue(LUZ), 390, 190, Settings::getInstance()->getYellowColor());
    
};

void General::drawElement(string element, int amount, int x, int y,  ofColor color, bool bLeft){
    ofPushMatrix();
    ofSetColor(color);
    ofTranslate(x, y);
    string s = ofToString(amount) + "%";
    int w = 50 - assets->fontLight.stringWidth(s);
    if(bLeft) w = 0;
    assets->drawString(s, w, 0, assets->fontLight);
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
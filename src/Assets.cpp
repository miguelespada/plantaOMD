//
//  Assets.cpp
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#include "Assets.h"


Assets::Assets(){
}

Assets* Assets::instance = 0;

Assets* Assets::getInstance(){
    if (instance == 0){
        instance = new Assets();
        instance->load();
    }
    return instance;
};

void Assets::load(){
    
    
    loadImage("planta.png", planta);
    
    viento = new Animation("08 Viento/viento_0", 4);
    niebla = new Animation("07 Niebla/niebla_0", 4);
    agua = new Animation("05 Agua/Agua_0", 3);
    luz = new Animation("06 Luz/luz_0", 3);
    flor = new Animation("09 flor/flor_0", 3);
    
    luz_bien = new Animation("Personajes/Luz/01_luz_bien_", 4);
    luz_regular = new Animation("Personajes/Luz/02_luz_regular_", 3);
    luz_mal = new Animation("Personajes/Luz/03_luz_mal_", 3);
    
    viento_bien = new Animation("Personajes/Viento/01_viento_bien_", 3);
    viento_regular = new Animation("Personajes/Viento/02_viento_reg_", 3);
    viento_mal = new Animation("Personajes/Viento/03_viento_mal_", 3);
    
    niebla_bien = new Animation("Personajes/Niebla/01_niebla_bien_", 3);
    niebla_regular = new Animation("Personajes/Niebla/02_niebla_regular_", 3);
    niebla_mal = new Animation("Personajes/Niebla/03_niebla_mal_", 3);
    
    agua_bien = new Animation("Personajes/Agua/01_agua_bien_", 4);
    agua_regular = new Animation("Personajes/Agua/02_agua_regular_", 3);
    agua_mal = new AnimationAguaMal("Personajes/Agua/03_agua_mal_", 5);
    
    font.loadFont("font/CPMono_v07 Light.otf", 10, true, true);
}

void Assets::loadImage(string filename, ofImage &destination){
    filename = Settings::getInstance()->assetsPath() + filename;
    destination.loadImage(filename);
    ofLogNotice() << "Loading: " << filename;
}


void Assets::drawString(string text, int x, int y){
    font.drawString(text, x, y);
}


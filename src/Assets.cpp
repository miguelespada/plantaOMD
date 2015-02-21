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
    string assets_path = Settings::getInstance()->assetsPath();
    ofLogNotice() << "Loading assets from: " << assets_path;
}
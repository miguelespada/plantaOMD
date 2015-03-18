//
//  Assets.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __carrousel__Assets__
#define __carrousel__Assets__

#include <stdio.h>
#include "ofMain.h"
#include "ofxJSON.h"
#include "Settings.h"
#include "Animation.h"
#include "AnimationAguaMal.h"


class Assets{
public:
    static Assets* getInstance();
    void load();
    void loadImage(string filename, ofImage &destination);
    void drawString(string text, int x, int y, ofTrueTypeFont font);
    
    ofImage planta;
    
    Animation *viento;
    Animation *agua;
    Animation *luz;
    Animation *niebla;
    
    Animation *luz_bien;
    Animation *luz_regular;
    Animation *luz_mal;
    
    Animation *viento_bien;
    Animation *viento_regular;
    Animation *viento_mal;
    
    Animation *niebla_bien;
    Animation *niebla_regular;
    Animation *niebla_mal;
    
    Animation *agua_bien;
    Animation *agua_regular;
    AnimationAguaMal *agua_mal;
    
    Animation *flor;
    
    ofTrueTypeFont fontPlainSmall;
    ofTrueTypeFont fontPlainMedium;
    ofTrueTypeFont fontPlainBig;
    ofTrueTypeFont fontLight;
    
private:
    static Assets* instance;
    Assets();
    
};

#endif /* defined(__carrousel__Assets__) */

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


class Assets{
public:
    static Assets* getInstance();
    void load();
    void loadImage(string filename, ofImage &destination);
    
    ofImage planta;
    Animation *viento;
    Animation *agua;
    Animation *luz;
    Animation *niebla;
    
    
private:
    static Assets* instance;
    Assets();
    
};

#endif /* defined(__carrousel__Assets__) */

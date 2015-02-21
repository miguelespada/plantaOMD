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


class Assets{
public:
    ~Assets();
    static Assets* getInstance();
    void load();

    
private:
    static Assets* instance;
    Assets();
};

#endif /* defined(__carrousel__Assets__) */
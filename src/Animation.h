//
//  Animation.h
//  planta
//
//  Created by miguel on 07/03/15.
//
//

#ifndef __planta__Animation__
#define __planta__Animation__

#include "ofMain.h"

class Animation{

protected:
    int max;
    int index;
    string path;
    
    ofImage *images;
    
    void draw_background();
    void loadImages();
    
public:
    
    Animation(string path, int n);
    void draw();
    void update();
};


#endif /* defined(__planta__Animation__) */

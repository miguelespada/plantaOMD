//
//  Info.h
//  planta
//
//  Created by miguel on 20/02/15.
//
//

#ifndef __planta__Info__
#define __planta__Info__

#include <stdio.h>
#include "ofMain.h"

class Info
{
    bool bInfo = false;
    string ss;
public:
    Info();
     ~Info(){};
    void draw();
    void toggle();
    void keyPressed(ofKeyEventArgs& eventArgs);
    void gotMessage(ofMessage& msg);
};
#endif /* defined(__planta__Info__) */

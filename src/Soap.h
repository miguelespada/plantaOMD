//
//  soap.h
//  planta
//
//  Created by miguel on 07/03/15.
//
//

#ifndef __planta__soap__
#define __planta__soap__

#include "ofMain.h"
#include "ofxJSON.h"

class Soap
{
    void fetchData();
    ofxJSONElement json;
    
public:
    Soap();
    int getValue(int index);
    void update(ofEventArgs &args);
};


#endif /* defined(__planta__soap__) */

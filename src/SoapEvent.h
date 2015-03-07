//
//  Events.h
//  planta
//
//  Created by miguel on 21/02/15.
//
//

#ifndef planta_SoapEvents_h
#define planta_SoapEvents_h
#pragma once
#include "ofMain.h"

class SoapEvent : public ofEventArgs {
    
public:
    
    int index;
    int value;
    
    SoapEvent() {}
    SoapEvent(int _index, int _value) {
        index = _index;
        value = _value;
    }
    
    static ofEvent <SoapEvent> SoapEvents;
};

#endif

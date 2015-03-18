//
//  Events.h
//  planta
//
//  Created by miguel on 21/02/15.
//
//

#ifndef planta_Events_h
#define planta_Events_h
#pragma once
#include "ofMain.h"

class ArduinoEvent : public ofEventArgs {
    
public:
    
    string key;
    int value;
    
    ArduinoEvent() {}
    ArduinoEvent(string _key, int _value) {
        key = _key;
        value = _value;
    }
    
    static ofEvent <ArduinoEvent> digitalEvents;
};

#endif

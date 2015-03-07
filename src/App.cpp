//
//  App.cpp
//  App
//
//  Created by miguel on 12/10/14.
//
//

#include "App.h"

App::App(){
    
    states[LUZ] = BIEN;
    states[VIENTO] = BIEN;
    states[NIEBLA] = BIEN;
    states[AGUA] = BIEN;
    
    // Register events and actions
    ofAddListener(ofEvents().keyPressed, this, &App::keyPressed);
    ofAddListener(ofEvents().update, this, &App::update);    
    ofAddListener(ArduinoEvent::digitalEvents, this, &App::arduinoEvent);
    ofAddListener(SoapEvent::SoapEvents, this, &App::soapEvent);
    
    soap = new Soap();
}

void App::setCurrentState(State *s){
    current_state = s;
}

void App::next(){
    current_state->next();
}

void App::jump(){
    current_state->jump();
}

void App::draw(){
    ofPushStyle();
    ofPushMatrix();
    current_state->draw();
    ofPopMatrix();
    ofPopStyle();
}

void App::update(){
    current_state->update();
    ofSendMessage("[Info] " + current_state->toString());
}

void App::update(ofEventArgs &args){
    update();
}

void App::keyPressed (ofKeyEventArgs& eventArgs){
    switch (eventArgs.key) {
        case 'n':
            next();
            break;
        case 'q':
            states[LUZ] = (int)ofClamp(states[LUZ] + 1, 0, 2);
            ofLogNotice() << "LUZ: " << states[LUZ];
            break;
        case 'a':
            states[LUZ] = (int)ofClamp(states[LUZ] - 1, 0, 2);
            ofLogNotice() << "LUZ: " << states[LUZ];
            break;
            
        case 'w':
            states[VIENTO] = (int)ofClamp(states[VIENTO] + 1, 0, 2);
            ofLogNotice() << "VIENTO: " << states[VIENTO];
            break;
            
        case 's':
            states[VIENTO] = (int)ofClamp(states[VIENTO] - 1, 0, 2);
            ofLogNotice() << "VIENTO: " << states[VIENTO];
            break;
            
        case 'e':
            states[NIEBLA] = (int)ofClamp(states[NIEBLA] + 1, 0, 2);
            ofLogNotice() << "NIEBLA: " << states[NIEBLA];
            break;
            
        case 'd':
            states[NIEBLA] = (int)ofClamp(states[NIEBLA] - 1, 0, 2);
            ofLogNotice() << "NIEBLA: " << states[NIEBLA];
            break;
            
        case 'r':
            states[AGUA] = (int)ofClamp(states[AGUA] + 1, 0, 2);
            ofLogNotice() << "AGUA: " << states[AGUA];
            break;
        case 'f':
            states[AGUA] = (int)ofClamp(states[AGUA] - 1, 0, 2);
            ofLogNotice() << "AGUA: " << states[AGUA];
            break;
            
        default:
            break;
    }
}

void App::soapEvent(SoapEvent &e){
    if(e.value < 50) states[e.index] = MAL;
    else if(e.value < 100) states[e.index] = REGULAR;
    else states[e.index] = BIEN;
}

void App::arduinoEvent(ArduinoEvent &e){
}

int App::getState(int state){
    return states[state];
}

int App::getSoapValue(int index){
    return soap->getValue(index);
}
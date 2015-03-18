//
//  App.cpp
//  App
//
//  Created by miguel on 12/10/14.
//
//

#include "App.h"

App::App(){
    // Register events and actions
    ofAddListener(ofEvents().keyPressed, this, &App::keyPressed);
    ofAddListener(ofEvents().update, this, &App::update);    
    ofAddListener(ArduinoEvent::digitalEvents, this, &App::arduinoEvent);
    ofAddListener(SoapEvent::SoapEvents, this, &App::soapEvent);
    
    for(int i = 0; i < 4; i++){
        actuators[i] = false;
    }
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
    ofBackground(Settings::getInstance()->getBackgroundColor());
    slogan.draw();
    current_state->draw();
    ofPopMatrix();
    ofPopStyle();
}

void App::update(){
    current_state->update();
    slogan.update();
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
            states[LUZ].inc(LUZ);
            break;
        case 'a':
            states[LUZ].dec(LUZ);
            break;
        
        case 'w':
            states[VIENTO].inc(VIENTO);
            break;
            
        case 's':
            states[VIENTO].dec(VIENTO);
            break;
            
        case 'e':
            states[NIEBLA].inc(NIEBLA);
            break;
            
        case 'd':
            states[NIEBLA].dec(NIEBLA);
            break;
            
        case 'r':
            states[AGUA].inc(AGUA);
            break;
        case 'f':
            states[AGUA].dec(AGUA);
            break;
            
        case '1':
            actuators[LUZ] = !actuators[LUZ];
            changeActuators();
            break;
        case '2':
            actuators[AGUA] = !actuators[AGUA];
            changeActuators();
            break;
        case '3':
            actuators[NIEBLA] = !actuators[NIEBLA];
            changeActuators();
            break;
        case '4':
            actuators[VIENTO] = !actuators[VIENTO];
            changeActuators();
            break;
            
        default:
            break;
    }

}


void App::changeActuators(){
    
    for(int i = 0; i < 4; i++){
        ofSendMessage("[Arduino]" + ofToString(i) + ";"  + ofToString(actuators[i]));
    }
    
}


void App::soapEvent(SoapEvent &e){
    if(e.value < 50)
        states[e.index].state = MAL;
    else if(e.value < 100)
        states[e.index].state = REGULAR;
    else
        states[e.index].state = BIEN;
    
    states[e.index].value = e.value;
    ofLogNotice() << "Set state " << states[e.index].toString(e.index);
}

void App::arduinoEvent(ArduinoEvent &e){
    if(e.key == "Temperature")
        temperature = e.value;
    else
        humidity = e.value;
        
}

int App::getPlantState(int index){
    return states[index].state;
}

int App::getPlantValue(int index){
    return states[index].value;
}

int App::getTemperature(){
    return temperature;
}

int App::getHumidity(){
    return humidity;
}
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
}

App::~App(){
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
}

void App::update(ofEventArgs &args){
    update();
}

void App::keyPressed (ofKeyEventArgs& eventArgs){
    switch (eventArgs.key) {
        case 'n':
            next();
            break;
        default:
            break;
    }
}

void App::arduinoEvent(ArduinoEvent &e){
}
//
//  App.cpp
//  App
//
//  Created by miguel on 12/10/14.
//
//

#include "App.h"
#include "Command.h"

App::App(){
    // Register actions
}

App::~App(){
    destroyCommands();
}

void App::notify(Action *action){
    // Chain of command
    current_state->notify(action);    
    run(action);
}

void App::setCurrent(State *s){
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



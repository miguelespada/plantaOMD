#ifndef App_App_h
#define App_App_h
#pragma once

#include "ofMain.h"
#include "State.h"
#include "ArduinoEvent.h"
#include "SoapEvent.h"

#define MAL 0
#define REGULAR 1
#define BIEN 2

#define LUZ 0
#define NIEBLA 1
#define AGUA 2
#define VIENTO 3

class App
{
    class PlantState{
    public:
        int value;
        int state;
        
        PlantState(){
            state = BIEN;
            value = 100;
        }
        
        string toString(int index){
            return indexToString(index) + ": " + ofToString(state) + " -> " + ofToString(value);
        }
        
        void inc(int index){
            state = (int)ofClamp(state + 1, 0, 2);
            ofLogNotice() << indexToString(index) << ":" <<  state;
        }
        
        void dec(int index){
            state = (int)ofClamp(state - 1, 0, 2);
            ofLogNotice() << indexToString(index) << ":" << state;
        }
        
        static string indexToString(int index){
            switch (index) {
                case LUZ:
                    return "Luz";
                    break;
                case NIEBLA:
                    return "Niebla";
                    break;
                case VIENTO:
                    return "Viento";
                    break;
                case AGUA:
                    return "Agua";
                    break;
                default:
                    break;
            }
        }
        
    };
    
    class Slogan{
        int x = 0;
        string s = "AHORA SI! ¡ESTOY ALUMBRADA Y REBOSANTE DE ENERGIA!";
        
        public:
        void draw(){
            ofPushStyle();
            ofSetColor(Settings::getInstance()->getBlueColor());
            Assets::getInstance()->drawString(s, x, 60, Assets::getInstance()->fontPlainBig);
            ofPopStyle();
        }
        
        void update(){
            if(ofGetFrameNum() % Settings::getInstance()->getAnimationRate() == 0){
                x -= 4;
            }
        };
    };
    
public:
    
    App();    
    class State *current_state;
    

    void setCurrentState(State *s);
    void keyPressed(ofKeyEventArgs& eventArgs);
    void update(ofEventArgs &args);
    
    void update();
    void next();
    void jump();
    void draw();
    
    
    int getPlantState(int state);
    int getPlantValue(int index);
    
    void arduinoEvent(ArduinoEvent &e);
    void soapEvent(SoapEvent &e);
    
    PlantState states[4];
    Slogan slogan;
};


#endif

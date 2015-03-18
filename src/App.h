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
            ofLogNotice() << indexToString(index) << "->" <<  stateToString(state);
        }
        
        void dec(int index){
            state = (int)ofClamp(state - 1, 0, 2);
            ofLogNotice() << indexToString(index) << "->" << stateToString(state);
        }
        
        static string indexToString(int index){
            switch (index) {
                case LUZ:
                    return "luz";
                    break;
                case NIEBLA:
                    return "niebla";
                    break;
                case VIENTO:
                    return "viento";
                    break;
                case AGUA:
                    return "agua";
                    break;
                default:
                    break;
            }
        }
        static string stateToString(int state){
            switch (state) {
                case 0:
                    return "mal";
                    break;
                case 1:
                    return "regular";
                    break;
                case 2:
                    return "bien";
                    break;
                default:
                    break;
            }
        }
        
    };
    
    class Slogan{
        int x;
        
        string s = "¡AHORA SI! ¡ESTOY ALUMBRADA Y REBOSANTE DE ENERGIA!";
        
        void init(){
            x = Assets::getInstance()->fontPlainBig.stringWidth(s) / 2 + 100;
        }
        
        public:
        Slogan(){
            init();
        }
        
        void draw(){
            ofPushStyle();
            ofSetColor(Settings::getInstance()->getBlueColor());
            Assets::getInstance()->drawString(s, x, 58, Assets::getInstance()->fontPlainBig);
            
            ofSetColor(Settings::getInstance()->getBackgroundColor());
            ofRect(0, 40, 42, 25);
            ofRect(Settings::getInstance()->getWidth() - 56, 40, 60, 25);
            ofPopStyle();
        }
        
        void update(){
            if(ofGetFrameNum() % Settings::getInstance()->getAnimationRate() == 0){
                x -= 8;
                if(x < - Assets::getInstance()->fontPlainBig.stringWidth(s)){
                    init();
                }
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
    int getTemperature();
    int getHumidity();
    
    void arduinoEvent(ArduinoEvent &e);
    void soapEvent(SoapEvent &e);
    
    PlantState states[4];
    Slogan slogan;
    
    int temperature = 0;
    int humidity = 0;
    
    bool actuators[4];
    void changeActuators();
};


#endif

//
//  Settings.h
//  carrousel
//
//  Created by miguel on 12/10/14.
//
//

#ifndef __Settings__
#define __Settings__

#include "ofxJSON.h"
#include "ofMain.h"

#define SCALE 1
#define WIDTH 800
#define HEIGHT 480

class Settings{
public:
    static Settings* getInstance();
    ~Settings();
    void load();
    string assetsPath();
    
    int getWidth();
    int getHeight();
    
    ofColor getBackgroundColor();

private:
    static Settings* instance;
    Settings();
    Settings(Settings const&);
    void operator=(Settings const&);
    
    ofxJSONElement json_file;
    Json::Value getData(string key);
};
#endif
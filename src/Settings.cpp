#include "Settings.h"
#include "Assets.h"

Settings::Settings(){
}

Settings* Settings::instance = 0;
Settings* Settings::getInstance(){
    if (instance == 0){
        instance = new Settings();
        instance->load();
    }
    return instance;
};

void Settings::load(){
    string path = ofToDataPath("settings.json");
    ofLogNotice() << "Loading settings from: " << path;
    json_file.open(path);
}

string Settings::assetsPath(){
    return ofToDataPath("General/" );
}

Json::Value Settings::getData(string key){
    return Settings::json_file[key];
}

int Settings::getWidth(){
    return Settings::getData("width").asInt() * Settings::getData("scale").asFloat();
}

int Settings::getHeight(){
    return Settings::getData("height").asInt() * Settings::getData("scale").asFloat();
}

ofColor Settings::getBackgroundColor(){
    string color = Settings::getData("background").asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}

int Settings::getAnimationRate(){
    return Settings::getData("animation_rate").asInt();
}
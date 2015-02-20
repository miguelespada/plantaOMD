#include "Settings.h"
#include "Assets.h"

Settings::Settings(){
    ofLogVerbose() << "Constructing Settings ";

}
Settings::~Settings(){
    ofLogVerbose() << "Destroying Settings ";
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
    json_file.open(ofToDataPath("settings.json"));
}

Json::Value Settings::getData(string key){
    return Settings::json_file[key];
}

int Settings::getWidth(){
    return WIDTH * SCALE;
}

int Settings::getHeight(){
    return HEIGHT * SCALE;
}

ofColor Settings::getBackgroundColor(){
    string color = Settings::getData("background").asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}


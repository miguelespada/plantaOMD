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

int Settings::getSoapRefreshRate(){
    return Settings::getData("soap_refresh_rate").asInt();
}


int Settings::getStateTime(){
    return Settings::getData("state_time").asInt();
}

ofColor Settings::getGrayColor(){
    string color = Settings::getData("gray").asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}

ofColor Settings::getYellowColor(){
    string color = Settings::getData("yellow").asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}
ofColor Settings::getBlueColor(){
    string color = Settings::getData("blue").asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}
ofColor Settings::getCyanColor(){
    string color = Settings::getData("cyan").asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}
ofColor Settings::getMagentaColor(){
    string color = Settings::getData("magenta").asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}

ofColor Settings::getWhiteColor(){
    string color = Settings::getData("white").asString();
    return ofColor::fromHex(ofHexToInt("0x" + color));
}

string Settings::getSlogan(string state){
    return Settings::getData(state).asString();
}


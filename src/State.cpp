//
//  State.cpp
//  planta
//
//  Created by miguel on 18/03/15.
//
//

#include "State.h"

void State::drawValue(string s, int y)
{
    ofPushMatrix();
    
    int w = assets->fontPlainSmall.stringWidth(s);
    int h = assets->fontPlainSmall.stringHeight(s);
    
    ofSetColor(Settings::getInstance()->getBackgroundColor());
    
    ofRect(Settings::getInstance()->getWidth()  - 200, Settings::getInstance()->getHeight()  - 80, 200, 80);
    
    ofTranslate(Settings::getInstance()->getWidth() - w - 20, y);
    
    ofNoFill();
    
    ofSetColor(Settings::getInstance()->getGrayColor());
    
    ofRect(-5, -h - 5, w + 10,  h * 2);
    
    Assets::getInstance()->drawString(s, 0, 0, assets->fontPlainSmall);
    ofPopMatrix();
}

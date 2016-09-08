//
//  Event.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "Event.hpp"

Delegate::EventDelegate::EventDelegate(UI::UIElementBase * instance) {
    this->UIInstance = instance;
}

void Delegate::EventDelegate::setMouseDownHandler(Delegate::MouseDownEventHandler handler)
{
    this->mouseDown = handler;
}

void Delegate::EventDelegate::setMouseUpHandler(Delegate::MouseUpEventHandler handler) {
    this->mouseUp = handler;
}

void Delegate::EventDelegate::setKeyPressHandler(Delegate::KeyPressEventHandler handler) {
    this->keyPress = handler;
}

void Delegate::EventDelegate::setMouseDownMotionHandler(Delegate::MouseDownMotionHandler handler) {
    this->mouseDownMotion = handler;
}

void Delegate::EventDelegate::invokeMouseDownHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 pos) const {
    if (this->mouseDown != NULL) {
        (UIInstance->*mouseDown)(button, pos);
    }
}

void Delegate::EventDelegate::invokeMouseUpHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 pos) const {
    if (this->mouseUp != NULL) {
        (UIInstance->*mouseUp)(button, pos);
    }
}

void Delegate::EventDelegate::invokeKeyPressHandler(unsigned char key, UI::Vector2 pos) const{
    if (this->keyPress != NULL) {
        (UIInstance->*keyPress)(key, pos);
    }
}

void Delegate::EventDelegate::invokeMouseDownMotinoHandler(UI::Vector2 mousePos) const{
    if (this->keyPress != NULL) {
        (UIInstance->*mouseDownMotion)(mousePos);
    }
}



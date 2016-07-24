//
//  Event.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "Event.hpp"


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

void Delegate::EventDelegate::invokeMouseDownHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 pos) const {
    if (this->mouseDown != nullptr) {
        this->mouseDown(button, pos);
    }
}

void Delegate::EventDelegate::invokeMouseUpHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 pos) const {
    if (this->mouseUp != nullptr) {
        this->mouseUp(button, pos);
    }
}

void Delegate::EventDelegate::invokeKeyPressHandler(unsigned char key, UI::Vector2 pos) const{
    if (this->keyPress != nullptr) {
        this->keyPress(key, pos);
    }
}

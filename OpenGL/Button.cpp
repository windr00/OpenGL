//
//  Button.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "Button.hpp"

UI::Button::Button(Delegate::Display * display) : UI::UIElementBase(display, {(Delegate::MouseDownEventHandler)(&Button::mouseDownHandler), (Delegate::MouseUpEventHandler)(&Button::mouseUpHandler), (Delegate::KeyPressEventHandler)(&Button::keyPressHandler), (Delegate::MouseDownMotionHandler)(&Button::mouseMotionHandler)}) {}



void UI::Button::keyPressHandler(unsigned char c, UI::Vector2 pos) {
    std::cout<<"Key Press: "<<c<<std::endl;
}

void UI::Button::mouseDownHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 mousePos) {
    if (button == Delegate::MOUSE_BUTTON::LEFT) {
        this->isLeftMosueButton = true;
        lastMousePosition = mousePos;
    }
    this->displayDelegate->setColor({0,0,127});
}

void UI::Button::mouseUpHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 mousePos) {
    this->displayDelegate->setColor({127,0,0});
    this->isLeftMosueButton = false;
}

void UI::Button::mouseMotionHandler(UI::Vector2 mouseMotion) {
    if (!isLeftMosueButton) {
        return;
    }
    int deltaX = mouseMotion.x - lastMousePosition.x;
    int deltaY = mouseMotion.y - lastMousePosition.y;
    auto currentPosition = this->displayDelegate->getPosition();
    this->displayDelegate->setPosition({currentPosition->x + deltaX, currentPosition->y + deltaY, currentPosition->z});
    lastMousePosition = mouseMotion;
}


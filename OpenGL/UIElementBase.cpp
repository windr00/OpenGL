//
//  UIElementBase.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "UIElementBase.hpp"

const Delegate::Display *  UI::UIElementBase::getDisplayDelegate(){
    return this->displayDelegate;
}

UI::UIElementBase::UIElementBase(Delegate::Display  * display,
                                 Delegate::MouseDownEventHandler mouseDown,
                                 Delegate::MouseUpEventHandler mouseUp,
                                 Delegate::KeyPressEventHandler keyPress) {
    this->displayDelegate = display;
    
    this->eventHandlers = new Delegate::EventDelegate();
    
    this->eventHandlers->setMouseDownHandler(mouseDown);
    
    this->eventHandlers->setMouseUpHandler(mouseUp);
    
    this->eventHandlers->setKeyPressHandler(keyPress);
}

UI::UIElementBase::~UIElementBase() {
    delete this->eventHandlers;
}

const Delegate::EventDelegate * UI::UIElementBase::getEventHandlers() {
    return this->eventHandlers;
}
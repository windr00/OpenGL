//
//  UIElementBase.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "UIElementBase.hpp"
#include "Event.hpp"
const Delegate::Display *  UI::UIElementBase::getDisplayDelegate(){
    return this->displayDelegate;
}

UI::UIElementBase::UIElementBase(Delegate::Display  * display,
                                 Delegate::EventHandlers handlers) {
    this->displayDelegate = display;
    
    this->eventHandlers = new Delegate::EventDelegate(this);
    
    this->eventHandlers->setMouseDownHandler(handlers.mouseDown);
    
    this->eventHandlers->setMouseUpHandler(handlers.mouseUp);
    
    this->eventHandlers->setKeyPressHandler(handlers.keyPress);
    
    this->eventHandlers->setMouseDownMotionHandler(handlers.mouseDownMotion);
}

UI::UIElementBase::~UIElementBase() {
    delete this->eventHandlers;
}

const Delegate::EventDelegate * UI::UIElementBase::getEventHandlers() {
    return this->eventHandlers;
}
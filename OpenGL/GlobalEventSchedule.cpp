//
//  GlobalEventSchedule.cpp
//  OpenGL
//
//  Created by Sophie Xiong on 16/7/22.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "GlobalEventSchedule.hpp"


Delegate::GlobalEventSchedule * Delegate::GlobalEventSchedule::getInstance() {
     static GlobalEventSchedule instance;
     return &instance;
}

void Delegate::GlobalEventSchedule::KeyBoardEventHandler(unsigned char c, int x, int y) {
    auto topElementHandler = this->UIElementList[this->selectedIndex]->getEventHandlers();
    
    topElementHandler->invokeKeyPressHandler(c, {static_cast<float>(x), static_cast<float>(y)});
}

void Delegate::GlobalEventSchedule::MouseEventHandler(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            std::cout<<"x: "<<x<<", "<<"y: "<<y<<std::endl;
            for (auto item : UIElementList) {
                
            }
        }
    }
    
    Delegate::MOUSE_BUTTON mouseButton = MOUSE_BUTTON(button);
    
    UI::Vector2 mousePosition = {static_cast<float>(x), static_cast<float>(y)};
    
    auto topElementHandler = this->UIElementList[selectedIndex]->getEventHandlers();
    
    if (state == GLUT_DOWN) {
        topElementHandler->invokeMouseDownHandler(mouseButton, mousePosition);
    }
    else {
        topElementHandler->invokeMouseUpHandler(mouseButton, mousePosition);
    }
    
    
    
}

void Delegate::GlobalEventSchedule::DisplayTriggerEventHandler() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    for (auto item : UIElementList) {
        auto display = item->getDisplayDelegate();
        if (display != NULL) {
            display->draw();
        }
    }
}

int Delegate::GlobalEventSchedule::UIElementApendEventHandler(UI::UIElementBase * element) {
    UIElementList.push_back(element);
    return (int)UIElementList.size() - 1;
}

void Delegate::GlobalEventSchedule::UIElementRemoveEventHandler(int index) {
    if (index < UIElementList.size()) {
        UIElementList.erase(UIElementList.begin() + index);
    }
}
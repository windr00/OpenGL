//
//  GlobalEventSchedule.cpp
//  OpenGL
//
//  Created by Sophie Xiong on 16/7/22.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "GlobalEventSchedule.hpp"

#include "Event.hpp"
Delegate::GlobalEventSchedule * Delegate::GlobalEventSchedule::getInstance() {
     static GlobalEventSchedule instance;
     return &instance;
}

void Delegate::GlobalEventSchedule::KeyBoardEventHandler(unsigned char c, int x, int y) {
    if (selectedIndex == -1) {
        return ;
    }
    auto topElementHandler = this->UIElementList[this->selectedIndex]->getEventHandlers();
    
    topElementHandler->invokeKeyPressHandler(c, {static_cast<float>(x), static_cast<float>(y)});
}

void Delegate::GlobalEventSchedule::MouseEventHandler(int button, int state, int mouseX, int mouseY) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            std::cout<<"x: "<<mouseX<<", "<<"y: "<<mouseY<<std::endl;
            selectedIndex = -1;
            float maxZ = -10.0f;
            int i = 0;
            for (i = 0; i < UIElementList.size(); i++) {
                auto display = UIElementList[i]->getDisplayDelegate();
                
                auto size = display->getSize();
                
                auto pos = display->getPosition();
                
                
                if (pos->x <= mouseX
                    && pos->x + size->x >= mouseX
                    && pos->y <= mouseY && pos->y + size->y >= mouseY ) {
                    if (pos->z >= maxZ) {
                        selectedIndex = i;
                        maxZ = pos->z;
                    }
                }
            }
            
            std::cout<<"selectedIndex: "<<selectedIndex<<std::endl;
            
        }
    }
    
    
    if (selectedIndex == -1) {
        return ;
    }
    
    Delegate::MOUSE_BUTTON mouseButton = MOUSE_BUTTON(button);
    
    UI::Vector2 mousePosition = {static_cast<float>(mouseX), static_cast<float>(mouseY)};
    
    auto topElementHandler = this->UIElementList[selectedIndex]->getEventHandlers();
    
    if (state == GLUT_DOWN) {
        topElementHandler->invokeMouseDownHandler(mouseButton, mousePosition);
    }
    else {
        topElementHandler->invokeMouseUpHandler(mouseButton, mousePosition);
    }
    
    
    
}

void Delegate::GlobalEventSchedule::MouseDownMotionHandler(int x, int y) {
    if (selectedIndex == -1) {
        return;
    }
    
    auto item = UIElementList[selectedIndex]->getEventHandlers();
    
    item->invokeMouseDownMotinoHandler({static_cast<float>(x),
        static_cast<float>(y)});
}

void Delegate::GlobalEventSchedule::DisplayTriggerEventHandler() {
    
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
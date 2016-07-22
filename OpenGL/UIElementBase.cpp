//
//  UIElementBase.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "UIElementBase.hpp"

void UI::UIElementBase::callDisplay(){
    if (displayDelegate != NULL) {
        displayDelegate->draw();
    }
}

UI::UIElementBase::UIElementBase(Delegate::Display  * display) {
    this->displayDelegate = display;
}
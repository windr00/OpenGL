//
//  Button.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef Button_hpp
#define Button_hpp

#include <stdio.h>
#include "UIElementBase.hpp"
#include "Defines.hpp"
namespace UI {
    
    class Button : public UI::UIElementBase{
    
    private:
        
        bool isLeftMosueButton = false;
        
        UI::Vector2 lastMousePosition;
        
        void keyPressHandler(unsigned char c, UI::Vector2 mousePos);
        
        void mouseDownHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 mousePos);
        
        void mouseUpHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 mousePos);
        
        void mouseMotionHandler(UI::Vector2 mouseMotion);
        
    public:
        
        Button(Delegate::Display * display);
        
        
    };
}


#endif /* Button_hpp */

//
//  Event.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include <iostream>
#include "Defines.hpp"
#include "UIElementBase.hpp"
namespace Delegate {
    
        class EventDelegate {
        
    private:
        
        MouseDownEventHandler mouseDown;
        
        MouseUpEventHandler mouseUp;
    
        KeyPressEventHandler keyPress;
            
        MouseDownMotionHandler mouseDownMotion;
        
        UI::UIElementBase * UIInstance;
        
    public:
        
        EventDelegate(UI::UIElementBase * instance);
        
        void setMouseDownHandler(Delegate:: MouseDownEventHandler);
        
        
        void setMouseUpHandler(Delegate:: MouseUpEventHandler);
        
        
        void setKeyPressHandler(Delegate::KeyPressEventHandler);
            
        void setMouseDownMotionHandler(Delegate::MouseDownMotionHandler);
        
        
        void invokeMouseDownHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 pos) const;
        
        void invokeMouseUpHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 pos) const ;
        
        void invokeKeyPressHandler(unsigned char key, UI::Vector2 pos)  const;
            
        void invokeMouseDownMotinoHandler(UI::Vector2 mousePos) const;
    };
}

#endif /* Event_hpp */

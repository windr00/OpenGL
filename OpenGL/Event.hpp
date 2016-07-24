//
//  Event.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef Event_hpp
#define Event_hpp

#include <stdio.h>
#include "Defines.hpp"
namespace Delegate {
    class EventDelegate {
        
    private:
        
        Delegate::MouseDownEventHandler mouseDown;
        
        Delegate::MouseUpEventHandler mouseUp;
    
        Delegate::KeyPressEventHandler keyPress;
        
    public:
        
        void setMouseDownHandler(Delegate:: MouseDownEventHandler);
        
        
        void setMouseUpHandler(Delegate:: MouseUpEventHandler);
        
        
        void setKeyPressHandler(Delegate::KeyPressEventHandler);
        
        
        void invokeMouseDownHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 pos) const;
        
        void invokeMouseUpHandler(Delegate::MOUSE_BUTTON button, UI::Vector2 pos) const ;
        
        void invokeKeyPressHandler(unsigned char key, UI::Vector2 pos)  const;
    };
}

#endif /* Event_hpp */

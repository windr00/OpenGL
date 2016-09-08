//
//  UIElementBase.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef UIElementBase_hpp
#define UIElementBase_hpp

#include <iostream>
#include <list>
#include "Defines.hpp"
#include "Display.hpp"
namespace  UI {
    class UIElementBase;
}

namespace Delegate {
    
    class EventDelegate;
    
    typedef void (UI::UIElementBase:: *MouseDownEventHandler) (Delegate::MOUSE_BUTTON mouseButton, UI::Vector2 mousePosition);
    
    typedef void (UI::UIElementBase:: *MouseUpEventHandler)(Delegate::MOUSE_BUTTON mouseButton, UI::Vector2 mousePosition);
    
    
    typedef void (UI::UIElementBase:: *KeyPressEventHandler) (unsigned char key, UI::Vector2 mousePosition);
    
    typedef void (UI::UIElementBase:: * MouseDownMotionHandler) (UI::Vector2 mousePosDelta);
    
     typedef struct
    {
        MouseDownEventHandler mouseDown;
        MouseUpEventHandler mouseUp;
        
        KeyPressEventHandler keyPress;
        
        MouseDownMotionHandler mouseDownMotion;
    
    }EventHandlers;
    

}

namespace UI {

    class UIElementBase {
    protected:
        
        
        Delegate::Display * displayDelegate;
        
        
        Delegate::EventDelegate * eventHandlers;
        
        
        ~UIElementBase();
        
    public:
        
        UIElementBase(Delegate::Display * display,
                      Delegate::EventHandlers handlers);
        
        const Delegate::Display * getDisplayDelegate();
        
        const Delegate::EventDelegate * getEventHandlers();
        
        
    
    };
}

#endif /* UIElementBase_hpp */

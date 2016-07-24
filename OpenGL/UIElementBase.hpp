//
//  UIElementBase.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef UIElementBase_hpp
#define UIElementBase_hpp

#include <stdio.h>
#include <list>
#include "Defines.hpp"
#include "Event.hpp"
#include "Display.hpp"
#include "MouseEventDelegate.hpp"
namespace UI {

    class UIElementBase {
    protected:
        
        
        Delegate::Display * displayDelegate;
        
        
        Delegate::EventDelegate * eventHandlers;
        
        
        ~UIElementBase();
        
    public:
        
        UIElementBase(Delegate::Display * display,
                      Delegate::MouseDownEventHandler mouseDown,
                      Delegate::MouseUpEventHandler mouseUp,
                      Delegate::KeyPressEventHandler keyPress);
        
        const Delegate::Display * getDisplayDelegate();
        
        const Delegate::EventDelegate * getEventHandlers();
        
        
    
    };
}

#endif /* UIElementBase_hpp */

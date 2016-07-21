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
namespace UI {

    class UIElementBase {
    protected:
        std::list<Delegate::Event> eventList;
        
        Delegate::Display * displayFunc;
        
        
        
    public:
        
        void callDisplay(){
            if (displayFunc != NULL) {
                displayFunc->display();
            }
        }
        
    private:
        
    ~UIElementBase(){
        if (displayFunc != NULL) {
            delete displayFunc;
        }
    }
        
    
    };
}

#endif /* UIElementBase_hpp */

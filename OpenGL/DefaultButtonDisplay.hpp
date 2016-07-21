//
//  DefaultButtonDisplay.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef DefaultButtonDisplay_hpp
#define DefaultButtonDisplay_hpp

#include <stdio.h>
#include "Display.hpp"
namespace Delegate {
    namespace DefultDisplay{
        
        class DefultButtonDisplay : protected Delegate::Display {
        public:
            
            DefultButtonDisplay(UI::Vector3 * pos, UI::Vector2 * size);
        
            virtual void draw() override;
        };
        
    }
    
}

#endif /* DefaultButtonDisplay_hpp */

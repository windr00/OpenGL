//
//  MouseEventDelegate.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/23.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef MouseEventDelegate_hpp
#define MouseEventDelegate_hpp

#include <stdio.h>
#include "Event.hpp"
namespace Delegate {
    class MouseEventDelegate {
        
    public:
        
        virtual void MouseClick(int button, int state, int x, int y) = 0;
        
    };
}

#endif /* MouseEventDelegate_hpp */

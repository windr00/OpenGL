//
//  Defines.h
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef Defines_h
#define Defines_h

namespace UI{
    
    typedef struct  {
        __int8_t red;
        __int8_t green;
        __int8_t blue;
    }Color3Byte;
    
    typedef struct  {
        float x;
        float y;
    }Vector2;
    
    typedef struct  {
        float x;
        float y;
        float z;
    }Vector3;
    
}


namespace Delegate {
    enum BUTTON_EVENT_TYPE {
        ONCLICK = 0,
        ONDRAG ,
    };
    
    enum MOUSE_BUTTON {
        LEFT = 0,
        MIDDLE = 1,
        RIGHT = 2,
    };
    
    
}


#endif /* Defines_h */

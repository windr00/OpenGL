//
//  Defines.h
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef Defines_h
#define Defines_h

namespace Delegate {
    enum BUTTON_EVENT_TYPE {
        ONCLICK = 0,
        ONDRAG ,
    };
}

namespace UI{
    
    typedef struct  {
        char red;
        char green;
        char blue;
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
    
    void displayButton();
}

#endif /* Defines_h */

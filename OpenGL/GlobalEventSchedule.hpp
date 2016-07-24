//
//  GlobalEventSchedule.hpp
//  OpenGL
//
//  Created by Sophie Xiong on 16/7/22.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef GlobalEventSchedule_hpp
#define GlobalEventSchedule_hpp

#include <iostream>
#include <vector>
#include "UIElementBase.hpp"
#include <GLUT/GLUT.h>
namespace Delegate {
    class GlobalEventSchedule {
        
    private:
        
        int selectedIndex;
        
        std::vector<UI::UIElementBase * > UIElementList;
        
    public :
        
        static GlobalEventSchedule * getInstance();
        
        void KeyBoardEventHandler(unsigned char c, int x, int y);
        
        void MouseEventHandler(int button, int state, int x, int y);
        
        void DisplayTriggerEventHandler();
        
        int UIElementApendEventHandler(UI::UIElementBase * element);
        
        void UIElementRemoveEventHandler(int index);
        
        
    
        
    };

}


#endif /* GlobalEventSchedule_hpp */

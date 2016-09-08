//
//  TextBox.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/27.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef TextBox_hpp
#define TextBox_hpp

#include <iostream>
#include "UIElementBase.hpp"

namespace UI {
    
    class TextBox : public UIElementBase {
    private:
        
        std::string text;
        
        void keyPressHandler(unsigned char c, UI::Vector2 mousePos);
        
        
    public:
        
        TextBox(Delegate::Display * );
        
        void setText(std::string *);
        
        const std::string getText();
    };
    
}

#endif /* TextBox_hpp */

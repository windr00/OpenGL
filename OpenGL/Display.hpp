//
//  Display.hpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#ifndef Display_hpp
#define Display_hpp

#include <stdio.h>
#include "Defines.hpp"
#include <vector>
#include <GLUT/GLUT.h>
namespace Delegate {
    class Display {
    protected:
        
        UI::Color3Byte * color;
        UI::Vector3 * position;
        UI::Vector2 * size;
        std::vector<UI::Vector3> vertexArray;
        
        Display() ;
        
        
    public:
        
        void setPosition( UI::Vector3 *);
        
        const UI::Vector3 * getPosition();
        
        void setSize( UI::Vector2 *);
        
        const UI::Vector2 * getSize();
        
        void setColor(UI::Color3Byte * color);
        
        const UI::Color3Byte * getColor();
        
        void addVertex(UI::Vector3 point);
        
        const std::vector<UI::Vector3> getVertexes();
        
        virtual void draw() = 0;
        ~Display() ;
    };
}

#endif /* Display_hpp */

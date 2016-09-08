//
//  DefaultButtonDisplay.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "DefaultButtonDisplay.hpp"
void Delegate::DefultDisplay::DefultButtonDisplay::draw() const{

    glBegin(GL_POLYGON);
    auto array = getVertexes();
    glColor3b(color->red, color->green, color->blue);
    for (int i = 0;i < array.size();i++) {
        auto point = array[i];
        glVertex3f(point.x, point.y, point.z);
        
    }
    glEnd();
    
    glColor3f(0, 0, 0);
    
    glRasterPos3f(position->x + (size->x / 2.0) - 6, position->y + (size->y / 2.0) + 6, position->z);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 'B');
}

Delegate::DefultDisplay::DefultButtonDisplay::DefultButtonDisplay(UI::Vector3 pos, UI::Vector2 size){
    this->setColor({127,0,0});
    this->setPosition(pos);
    this->setSize(size);
    this->addVertex({pos.x, pos.y, pos.z});
    this->addVertex({pos.x + size.x, pos.y, pos.z});
    this->addVertex({pos.x + size.x, pos.y + size.y, pos.z});
    this->addVertex({pos.x, pos.y + size.y, pos.z});
}
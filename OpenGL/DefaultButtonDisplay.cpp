//
//  DefaultButtonDisplay.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "DefaultButtonDisplay.hpp"

void Delegate::DefultDisplay::DefultButtonDisplay::draw() {

    glBegin(GL_POLYGON);
    auto array = this->getVertexes();
    glColor3b(127, 0, 0);
    for (int i = 0;i < array.size();i++) {
        auto point = array[i];
        glVertex3f(point.x, point.y, point.z);
    }
    
    glEnd();
    glFlush();
    
}

Delegate::DefultDisplay::DefultButtonDisplay::DefultButtonDisplay(UI::Vector3 * pos, UI::Vector2 * size){
    this->setPosition(pos);
    this->setSize(size);
    this->addVertex({pos->x, pos->y, pos->z});
    this->addVertex({pos->x + size->x, pos->y, pos->z});
    this->addVertex({pos->x + size->x, pos->y - size->y, pos->z});
    this->addVertex({pos->x, pos->y - size->y, pos->z});
}
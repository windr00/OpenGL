//
//  main.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>
#include "DefaultButtonDisplay.hpp"
#include "Button.hpp"
#include <cstdlib>
std::vector<UI::UIElementBase * > UIElementList;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto item : UIElementList) {
        item->callDisplay();
        
    }
}

void keyfunc(unsigned char key, int x, int y) {
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    glutInit(&argc, (char **)argv);
    glutCreateWindow("Xcode OpenGL Test");
    UI::Vector3 pos = {-0.25,0.25,0};
    UI::Vector2 size = {0.5,0.5};
    UI::Button btn(new Delegate::DefultDisplay::DefultButtonDisplay(&pos, &size));
    UIElementList.push_back(&btn);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyfunc);
    std::cout<<"Hello World"<<std::endl;
    
    glutMainLoop();
    return 0;
}

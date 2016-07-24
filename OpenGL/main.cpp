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
#include "GlobalEventSchedule.hpp"

Delegate::GlobalEventSchedule * handler ;

int width = 400;
int height = 300;

void display() {
    handler->DisplayTriggerEventHandler();
}

void keyfunc(unsigned char key, int x, int y) {
    handler->KeyBoardEventHandler(key, x, y);
}

void mousefunc(int button, int state, int x, int y) {
    handler->MouseEventHandler(button, state, x, y);
}

void reshapefunc(int w, int h) {
    /*float ratio = 1.0* w / h;
    
    // 单位化投影矩阵。
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // 设置视口大小为增个窗口大小
    glViewport(0, 0, w, h);
    
    // 设置正确的投影矩阵
    gluPerspective(45,ratio,1,1000);
    //下面是设置模型视图矩阵
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,5.0, 0.0,0.0,-1.0,0.0f,1.0f,0.0f);
    */
    
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    glOrtho(0, w, h,0, -10, 10);

}

void test() {
    
    UI::Vector3 pos = {100,100,0};
    UI::Vector2 size = {50,50};
    UI::Button * btn = new UI::Button(new Delegate::DefultDisplay::DefultButtonDisplay(&pos, &size));
    handler->UIElementApendEventHandler(btn);
}

int main(int argc, const char * argv[]) {
    glutInit(&argc, (char **)argv);
    glutInitWindowSize(width, height);
    glutCreateWindow("Xcode OpenGL Test");
    handler = Delegate::GlobalEventSchedule::getInstance();
    test();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyfunc);
    glutMouseFunc(mousefunc);
    glutReshapeFunc(reshapefunc);
    std::cout<<"Hello World"<<std::endl;
    
    glutMainLoop();
    return 0;
}

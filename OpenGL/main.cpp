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
    glClearColor(236.0/255, 236.0/255, 236.0/255,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    handler->DisplayTriggerEventHandler();
    glFlush();
}

void keyfunc(unsigned char key, int x, int y) {
    handler->KeyBoardEventHandler(key, x, y);
    glutPostRedisplay();
}

void mousefunc(int button, int state, int x, int y) {
    handler->MouseEventHandler(button, state, x, y);
    glutPostRedisplay();
}

void reshapefunc(int w, int h) {
    
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    
    glMatrixMode(GL_PROJECTION);
    
    glLoadIdentity();
    
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();
    
    glOrtho(0, w, h,0, -10, 10);

}

void motion(int x, int y) {
    // std::cout<<"Motion :"<<x<<","<<y<<std::endl;
    
    handler->MouseDownMotionHandler(x, y);
    glutPostRedisplay();
}

void test() {
    
    UI::Vector3 pos = {200,200,0};
    UI::Vector2 size = {80,40};
    UI::Button * btn = new UI::Button(new Delegate::DefultDisplay::DefultButtonDisplay(pos, size));
    handler->UIElementApendEventHandler(btn);
}


int main(int argc, const char * argv[]) {
    glutInit(&argc, (char **)argv);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Xcode OpenGL Test");
    handler = Delegate::GlobalEventSchedule::getInstance();
    test();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyfunc);
    glutMouseFunc(mousefunc);
    glutReshapeFunc(reshapefunc);
    glutMotionFunc(motion);
    glutMainLoop();
    return 0;
}

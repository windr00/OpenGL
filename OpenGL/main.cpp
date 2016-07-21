//
//  main.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include <iostream>
#include <GLUT/GLUT.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3b(127, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();
    glFlush();
}

void keyfunc(unsigned char key, int x, int y) {
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    glutInit(&argc, (char **)argv);
    glutCreateWindow("Xcode OpenGL Test");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyfunc);
    
    glutMainLoop();
    return 0;
}

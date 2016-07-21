//
//  Display.cpp
//  OpenGL
//
//  Created by 冉惟之 on 16/7/20.
//  Copyright © 2016年 冉惟之. All rights reserved.
//

#include "Display.hpp"

Delegate::Display::Display() {
    this->position = new UI::Vector3;
    this->position->x = 0;
    this->position->y = 0;
    this->position->z = 0;
    
    this->size = new UI::Vector2;
    this->size->x = 0;
    this->size->y = 0;
    
    this->color = new UI::Color3Byte;
    this->color->red = 0;
    this->color->green = 0;
    this->color->blue = 0;
    
    
}

Delegate::Display::~Display() {
    if (this->position != NULL) {
        delete this->position;
    }
    if (this->size != NULL ) {
        delete this->size;
    }
    if (this->color != NULL) {
        delete this->color;
    }
}

void Delegate::Display::setPosition( UI::Vector3 * pos) {
    this->position->x = pos->x;
    this->position->y = pos->y;
    this->position->z = pos->z;
    
    
}


const  UI::Vector3 * Delegate::Display::getPosition() {
    return this->position;
}

const  UI::Vector2 * Delegate::Display::getSize() {
    return this->size;
}

void Delegate::Display::setSize( UI::Vector2 * size) {
    this->size->x = size->x;
    this->size->y = size->y;
}

void Delegate::Display::setColor(UI::Color3Byte * col) {
    this->color->red = col->red;
    this->color->green = col->green;
    this->color->blue = col->blue;
}

const UI::Color3Byte * Delegate::Display::getColor() {
    return this->color;
}
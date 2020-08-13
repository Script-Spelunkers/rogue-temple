#include "boundingbox.h"


float aabb_bounding_box::getX(){

    return x;

}

float aabb_bounding_box::getY(){

    return y;

}

float aabb_bounding_box::getWidth(){

    return width;

}

float aabb_bounding_box::getHeight(){

    return height;

}

bool aabb_bounding_box::getActive(){

    return active;

}

bool aabb_bounding_box::getDraw(){

    return draw;

}


void aabb_bounding_box::setX(float x){

    this->x = x;

}


void aabb_bounding_box::setY(float y){

    this->y = y;

}
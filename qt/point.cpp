#include "point.h"

Point::Point (int _x, int _y)
    :x(_x),y(_y)
{}

int Point::getX(){
    return x;
}

int Point::getY(){
    return y;
}

void Point::setX(int x1){
    x = x1;
}

void Point::setY(int y1){
    y = y1;
}

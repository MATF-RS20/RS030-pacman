#include "point.h"

Point::Point ()
    :x(0),y(0)
{}


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

Point Point::operator-(Point p1)
{
    return Point(this->x - p1.x, this->y - p1.y);
}

int Point::length(){
    // ne znam odakle rastojanje
}

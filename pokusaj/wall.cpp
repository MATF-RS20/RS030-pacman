#include "wall.h"

Wall::Wall(int x1, int y1, int width1, int height1)
    :x(x1), y(y1), width(width1), height(height1)
{
    setRect(x, y, width, height);
}

Wall::Wall(Wall &wall)
    :Wall(wall.pos().x(), wall.pos().y(), wall.getWidth(), wall.getHeight())
{  /*
    this->height = wall.getHeight();
    this->width = wall.getWidth();
    this->pos.x = wall.pos.x;
    this->pos.y = wall.pos.y;
    setRect(this->pos.x, this->pos.y, this->width, this->height);
    */
}

int Wall::getWidth(){
    return this->width;
}
int Wall::getHeight(){
    return this->height;
}
/*
int Wall::getPosX(){
    return this->pos.x;
}
int Wall::getPosY(){
    return this->pos.y;
}
*/

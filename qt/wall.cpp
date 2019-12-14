#include "wall.h"

Wall::Wall(int x, int y, int width, int height){
    setRect(x, y, width, height);
    this->height = height;
    this->width = width;
    this->pos.x = x;
    this->pos.y = y;
}

Wall::Wall(Wall &wall)
{
    this->height = wall.getHeight();
    this->width = wall.getWidth();
    this->pos.x = wall.pos.x;
    this->pos.y = wall.pos.y;
    setRect(this->pos.x, this->pos.y, this->width, this->height);
}

int Wall::getWidth(){
    return this->width;
}
int Wall::getHeight(){
    return this->height;
}
int Wall::getPosX(){
    return this->pos.x;
}
int Wall::getPosY(){
    return this->pos.y;
}
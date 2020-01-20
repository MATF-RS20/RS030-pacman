#include "wall.h"

Wall::Wall(int x, int y, int width, int height){
    //setRect(x, y, width, height);
    if(width == 13){
        setPixmap(QPixmap(":/Puck/vrata.png"));
    }
    else if(width == 20)
        setPixmap(QPixmap(":/Puck/pattern1.jpg"));  // 35 is spacing from PacmanGame
    else
        setPixmap(QPixmap(":/Puck/pattern.jpg"));  // 35 is spacing from PacmanGame
    setPos(x,y);
    this->height = height;
    this->width = width;
    this->pos.x = x;
    this->pos.y = y;
}

Wall::Wall(Wall &wall)
    :Wall(wall.pos.x, wall.pos.y, wall.getWidth(), wall.getHeight())
{
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

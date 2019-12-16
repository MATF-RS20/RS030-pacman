#include "Character.h"



Character::Character(int x, int y, int width, int height, int sizeX, int sizeY)
{
    setRect(x, y, width, height);
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->width = width;
    this->height = height;

    this->horizontal_step = 5;
    this->vertical_step = 5;

    this->currentDirection = 0;
    this->nextDirection = 0;

    this->availableDirections[0] = false;
    this->availableDirections[1] = false;
    this->availableDirections[2] = false;
    this->availableDirections[3] = false;



}


void Character::move()
{
    if(this->currentDirection == 1)
        setPos(x() - horizontal_step, y());
    else if(this->currentDirection == 2)
        setPos(x() + horizontal_step, y());
    else if(this->currentDirection == 3)
        setPos(x(), y() - vertical_step);
    else if(this->currentDirection == 4)
        setPos(x(), y() + vertical_step);

    if(x() < 0)
        setPos(0, y());
    if(y() < 0)
        setPos(x(), 0);
    if(x() > sizeX - this->width)
        setPos(sizeX  - this->width, y());
    if(y() > sizeY - this->height)
        setPos(x(), sizeY - this->height);



}


void Character::setNextDirection(int where){
    this->nextDirection = where;
}

bool Character::isAvailable(int where){
    if(this->availableDirections[where - 1])
        return true;
    return false;
}

void Character::setCurrentDirection(int where){
    this->currentDirection = where;
}

void Character::setAvailable(int i, bool yesNo){
    this->availableDirections[i - 1] = yesNo;
}
int Character::getWidth(){
    return this->width;
}
int Character::getHeight(){
    return this->height;
}
bool* Character::getAvailableDirections(){
    return this->availableDirections;
}
int Character::getNextDirection(){
    return this->nextDirection;
}
int Character::getCurrentDirection(){
    return this->currentDirection;
}

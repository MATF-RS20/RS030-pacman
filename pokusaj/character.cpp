#include "character.h"


Character::Character(int x1, int y1, int width1, int height1)
    :x(x1), y(y1), width(width1), height(height1)
{
    setRect(x, y, width, height);

}



/*
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
*/

int Character::getWidth(){
    return this->width;
}
int Character::getHeight(){
    return this->height;
}

int Character::getX(){
    return x;
}

int Character::getY(){
    return y;
}


//----------------------------------------------------------
/*
Character::Character(int x1, int y1, int width1, int height1)
    :x(x1), y(y1), width(width1), height(height1)
{
    setRect(x1,y1,width1,height1);
}

int Character::getHeight(){
    return height;
}

int Character::getWidth(){
    return width;
}
int Character::getX(){
    return x;
}

int Character::getY(){
    return y;
}
*/

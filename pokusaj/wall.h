#ifndef WALL_H
#define WALL_H

//#include <Character.h>
//#include "character.h"
// mislim da ne treba ovde ujljuciti klasu "character.h" nego koliziju ispitivati ili u njoj ili u klasi pacmangame
#include <QGraphicsRectItem>


/*
typedef struct position {
    int x;
    int y;
}Position;
*/

class Wall: public QGraphicsRectItem
{
public:
    Wall(int x, int y, int width, int height);
    Wall(Wall &wall);
    int getWidth();
    int getHeight();

private:
    //Position pos;
    int x;
    int y;
    int width;
    int height;
};


#endif // WALL_H

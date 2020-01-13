#ifndef WALL_H
#define WALL_H


#include <QGraphicsRectItem>



typedef struct position {
    int x;
    int y;
}Position;


class Wall: public QGraphicsRectItem
{
private:
    Position pos;
    int height;
    int width;
public:
    Wall(int x, int y, int width, int height);
    Wall(Wall &wall);
    int getWidth();
    int getHeight();
    int getPosX();
    int getPosY();
};

#endif // WALL_H

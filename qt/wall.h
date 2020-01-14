#ifndef WALL_H
#define WALL_H


#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>



typedef struct position {
    int x;
    int y;
}Position;


class Wall: public QGraphicsPixmapItem
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

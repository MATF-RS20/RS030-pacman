#ifndef GHOST_H
#define GHOST_H

//#include "character.h"
#include <QObject>
#include <QGraphicsRectItem>

class Ghost: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Ghost ();
    //Ghost(int x1, int y1, int width1, int height1);
public slots:
    void move();
/*
private:
    int x;
    int y;
    int width;
    int height;
*/
}; //end of class Ghost


#endif // GHOST_H

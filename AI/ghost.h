#ifndef GHOST_H
#define GHOST_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QCoreApplication>

#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include "wall.h"

enum Ghost_Id{
    prvi = 1,
    drugi = 2,
    treci = 3,
    cetvrti = 4
};

class Ghost: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    //Ghost ();
    Ghost(int x1, int y1, int id);
    int getX();
    int getY();
public slots:
    void colision();
    void chooseRandom();
private:
    // 1 - left; 2 - right; 3 - up; 4 - down; 0 - none
    int currentDirection = 0;
    int nextDirection = 0;
    int x1;
    int y1;
    Ghost_Id ghost_id;       // in every game there are 4 ghosts so id can be only 1,2,3,4


}; //end of class Ghost


#endif // GHOST_H

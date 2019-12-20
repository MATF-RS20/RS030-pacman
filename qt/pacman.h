#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsRectItem>
//#include "character.h"
#include <QKeyEvent>
#include <QCoreApplication>

#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include "wall.h"



class Pacman: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Pacman();
    /*
    Pacman(int x1, int y1, int width1, int height1);
    int getHeight();
    int getWidth();
*/
    void keyPressEvent(QKeyEvent *event);

// move se nalazi u slots da bi mogao tajmer da ga zove
// da, ovde sam odustao od engleskog
//
// move mora da bude pozivan stalno zato sto mora da se konstantno pomera pacman
// on staje samo ako udari u zid
public slots:
    void move();
private:

    // We need current_direction for continual movement, and also for solving colision
    // We need next_direction to remember next move until next viable direction change

    // 1 - left; 2 - right; 3 - up; 4 - down; 0 - none
    int currentDirection = 0;
    int nextDirection = 0;
//    int x;
//    int y;
//    int width;
//    int height;
}; //end of class Pacman

#endif // PACMAN_H
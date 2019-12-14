#ifndef PACMAN_H
#define PACMAN_H

#include <QGraphicsRectItem>
//#include "character.h"
#include <QKeyEvent>
#include <QCoreApplication>


class Pacman: public QGraphicsRectItem{
public:
    Pacman();
    /*
    Pacman(int x1, int y1, int width1, int height1);
    int getHeight();
    int getWidth();
*/
    void keyPressEvent(QKeyEvent *event);
/*
private:
    int x;
    int y;
    int width;
    int height;
*/
}; //end of class Pacman

#endif // PACMAN_H

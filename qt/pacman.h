#ifndef PACMAN_H
#define PACMAN_H


#include <iostream>
#include "dot.h"
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QCoreApplication>

#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <QTimer>
#include "wall.h"
#include "ghost.h"
//#include <QMediaPlayer>



class Pacman: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Pacman(int x1, int y1, int dotsInMap = 156);

    int getX();
    int getY();

    int eatenDots=0;
    int dotsToEat=156;
    int lc = 0;

    void keyPressEvent(QKeyEvent *event);
    void setCurrentDirection(int x);
    void setNextDirection(int x);
    void setDirs0();
    QTimer *timer_jedi = new QTimer(this);
    QTimer *timerLastChance = new QTimer(this);


// move se nalazi u slots da bi mogao tajmer da ga zove
// da, ovde sam odustao od engleskog
//
// move mora da bude pozivan stalno zato sto mora da se konstantno pomera pacman
// on staje samo ako udari u zid
public slots:
    void move();
    void animation();
    void jedi();
    void last_chance();
private:

    // We need current_direction for continual movement, and also for solving colision
    // We need next_direction to remember next move until next viable direction change

    // 1 - left; 2 - right; 3 - up; 4 - down; 0 - none
    int currentDirection = 0;
    int nextDirection = 0;

    // probao da ubacim zvukove pa nije htelo da se pokrene :)
    /*
    QMediaPlayer * beginning;
    QMediaPlayer * chomp;
    QMediaPlayer * eatfruit;
    QMediaPlayer * eatghost;
    QMediaPlayer * death;
    */
    int x1;
    int y1;
    int current_score = 0;
    double korektivni_faktor = 1;
}; //end of class Pacman

#endif // PACMAN_H

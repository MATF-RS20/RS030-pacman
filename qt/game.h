#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QScreen>
#include "pacmangame.h"
#include "button.h"

#include <QDebug>
#include "wall.h"

class Game: public QGraphicsView
{
       Q_OBJECT
public:

    PacmanGame *game1;
    QGraphicsScene *scene;
    Game(QWidget *parent = NULL);
    void displayMainManu();
    void youLost();
    void youWon();

public slots:
    void start();
};

#endif // GAME_H

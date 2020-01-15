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
#include <QGraphicsPixmapItem>

class Game: public QGraphicsView
{
       Q_OBJECT
public:

    PacmanGame *game1;
    QGraphicsScene *scene;
    Game(QWidget *parent = NULL);
    void displayMainManu();
    void gameOver(QString message);

public slots:
    void start(int level_map);
    void resetGame();
};

#endif // GAME_H

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
#include <list>

extern std::list<std::pair<std::string, int> > listOfScores;

extern QString playersName;
extern QString player;


class Game: public QGraphicsView
{
       Q_OBJECT
public:
    int mapSelector;
    PacmanGame *game1;
    QGraphicsScene *scene;
    QGraphicsScene *highScene;
    unsigned howManyGames = 1;


    Game(QWidget *parent = NULL);
    void displayMainManu();
    void gameOver(QString message);
    void again();
    int getMapX() const;
    int getMapY() const;
    void gameStop();
    std::vector<std::pair<QString*,int>> highScores{10};
    bool highScoresLoaded = false;
    void tastatura(QGraphicsScene *highScene);
    void writeName(QString x);

public slots:
    //auto f();
    void start();
    void score();
    void resetGame();
    //void changeScene();
};

#endif // GAME_H

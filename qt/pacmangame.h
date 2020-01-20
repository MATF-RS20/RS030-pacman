#ifndef PACMANGAME_H
#define PACMANGAME_H

#include <vector>

#include <QSize>
#include <QGraphicsScene>
#include <QTimer>
#include <QPainter>

#include "wall.h"
#include "pacman.h"
#include "ghost.h"
#include "score.h"
#include "health.h"


#include <list>
#include <map>
//#include <QMediaPlayer>
#include "dot.h"

//#include <QGraphicsItemGroup>


class PacmanGame:  public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    Pacman *pacman;
    Ghost *ghost;

    std::list<Wall*> walls_and_borders{};
    std::map<std::pair<int,int>,Dot*> dots{};

/*
    QMediaPlayer * beginning;
    QMediaPlayer * chomp;
    QMediaPlayer * eatfruit;
    QMediaPlayer * eatghost;
    QMediaPlayer * death;
*/


    int x;
    int y;
    int width = 0;
public:
    std::list<Ghost*> ghosts{};
    PacmanGame(int selectMap, int hearts = 3, int scr = 0);
    Score *score;
    std::vector<std::pair<QString*,int>> highScores{10};
    void readScores();
    bool pojedi = false;

    Health *health;
    int pacPosX;
    int pacPosY;
    int mapSelector;
    int flag =0;
    virtual ~PacmanGame();
    Pacman* getPacman();
    Wall* getWall();
    int getWidth();
    int getHeight();
    void populateScene(QGraphicsScene &scene);
    void setMapSelector(int x);
    int getX() const;
    int getY() const;
    void sendGhostsToStartPos();
};

#endif // PACMANGAME_H

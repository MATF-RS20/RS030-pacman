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
    std::list<Ghost*> ghosts{};
//obrisala current_score, nalazi se u pacman klasi
    Wall *walls[200];
    std::list<Wall*> walls_and_borders{};
    std::map<std::pair<int,int>,Dot*> dots{};
/*
    QMediaPlayer * beginning;
    QMediaPlayer * chomp;
    QMediaPlayer * eatfruit;
    QMediaPlayer * eatghost;
    QMediaPlayer * death;
*/
    //  tabela skorova !!!
    //  bolje tipa vektor sa 10 mesta, da otmemo odmah 10 slotova
    //  za skorove, da ne alociramo memoriju ako je slucajno nema

public:
    PacmanGame();
    virtual ~PacmanGame();
    Pacman* getPacman();
    Wall* getWall();
    int getWidth();
    int getHeight();
    void populateScene(QGraphicsScene &scene);
};

#endif // PACMANGAME_H

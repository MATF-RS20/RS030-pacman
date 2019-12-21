#ifndef PACMANGAME_H
#define PACMANGAME_H

#include "Character.h"
#include "wall.h"
#include <vector>

#include <QSize>
#include <QGraphicsScene>
#include <QTimer>
#include <QPainter>

#include "wall.h"
#include "pacman.h"

#include <list>

//#include <QGraphicsItemGroup>


class PacmanGame:  public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    Pacman *pacman;
    Character *ghosts[4];
    int current_score;
    Wall *walls[200];
    std::list<Wall*> walls_and_borders{};
    //  tabela skorova

public:
    PacmanGame();
    virtual ~PacmanGame();
    Pacman* getPacman();
    Wall* getWall();
    int getWidth();
    int getHeight();
    //void keyPressEvent(QKeyEvent *event);
    void populateScene(QGraphicsScene &scene);
public slots:
    //void checkAvailableDirections();
    //void setCurrentDirection();
};

#endif // PACMANGAME_H

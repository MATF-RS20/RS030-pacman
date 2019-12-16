#ifndef PACMANGAME_H
#define PACMANGAME_H

#include "Character.h"
#include "wall.h"
#include <vector>

#include <QSize>
#include <QGraphicsScene>
#include <QTimer>
#include "wall.h"
#include "pacman.h"


class PacmanGame:  public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    Pacman *pacman;
    Character *ghosts[4];
    int current_score;
    Wall *walls[50];
    //  tabela skorova

public:
    PacmanGame();
    virtual ~PacmanGame();
    Pacman* getPacman();
    Wall* getWall();
    //void keyPressEvent(QKeyEvent *event);
    void populateScene(QGraphicsScene &scene);
public slots:
    //void checkAvailableDirections();
    //void setCurrentDirection();
};

#endif // PACMANGAME_H

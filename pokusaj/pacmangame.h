#ifndef PACMANGAME_H
#define PACMANGAME_H


//#include "character.h"
#include <vector>

#include <QSize>
#include <QGraphicsScene>

#include "wall.h"
#include "pacman.h"
#include "ghost.h"

class PacmanGame: public QGraphicsRectItem{
public:
    PacmanGame();
    virtual ~PacmanGame();
    Pacman* getPacman();
    Wall* getWall();
    //void keyPressEvent(QKeyEvent *event);
    void populateScene(QGraphicsScene &scene);
private:
    Pacman *pacman;
    //Ghost *ghosts[4];
    int current_score;
    Wall *walls[50];
    //int current_score; MOZDA BOLJE KLASA SCORE
    //  tabela skorova

};


#endif // PACMANGAME_H

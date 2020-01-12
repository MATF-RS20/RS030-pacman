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

#include <limits>
#include <math.h>   // fabs
#define MAX_X 17
#define MAX_Y 24
#include <cfloat>
#include <stack>    //makePath
#include <exception>
#include "node.h"
//#define FLT_MAX numeric_limits<float>::max()
//#define FLT_MAX numeric_limits<float>::infinity()



class PacmanGame:  public QObject, public QGraphicsRectItem{
    Q_OBJECT
private:
    Pacman *pacman;
    Ghost *ghost;
    std::list<Ghost*> ghosts{};
    std::vector <std::vector <Node*> > mapa = std::vector <std::vector <Node*> >(MAX_Y , std::vector<Node*> (MAX_X));
    //std::vector <std::vector <Node*> > mapa = std::vector <std::vector <Node*> >(MAX_X , std::vector<Node*> (MAX_Y));
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

    float ManhattanDistance(int x, int y, Node dest);
    bool isDestination(int x, int y, Node dest);
    bool isValid(int x, int y);
    std::vector<Node> makePath(std::vector <std::vector <Node*> > map, Node dest);
public slots:
    std::vector<Node> aStar (Node player, Node destination);
};



#endif // PACMANGAME_H

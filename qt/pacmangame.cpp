#include "pacmangame.h"

#include <iostream>
#include <QDesktopWidget>
#include <QApplication>

#include<QGraphicsItemGroup>
#include <fstream>
#include <QFile>
#include <stdio.h>
#include <QTextStream>
#include <QChar>
#include <list>
#include <numeric>

PacmanGame::PacmanGame()
{
    this->pacman = new Pacman();
    this->pacman->setBrush(Qt::yellow);

    this->current_score = 0;

    /*
    Wall *w1 = new Wall(50, 400, 10, 200);
    this->walls[0] = w1;
    Wall *w2 = new Wall(100, 450, 10, 200);
    this->walls[1] = w2;
    Wall *w3 = new Wall(150, 400, 10, 200);
    this->walls[2] = w3;
    Wall *w4 = new Wall(200, 450, 10, 200);
    this->walls[3] = w4;
    Wall *w5 = new Wall(250, 400, 10, 200);
    this->walls[4] = w5;
    Wall *w6 = new Wall(300, 450, 10, 200);
    this->walls[5] = w6;
    Wall *w7 = new Wall(350, 400, 10, 200);
    this->walls[6] = w7;
    Wall *w8 = new Wall(400, 450, 10, 200);
    this->walls[7] = w8;
    Wall *w9 = new Wall(50, 390, 400, 10);
    this->walls[8] = w9;
    */
    // Izmene:

/*
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkAvailableDirections()));
    connect(timer, SIGNAL(timeout()), this, SLOT(setCurrentDirection()));
    connect(timer, SIGNAL(timeout()), this->getPacman(), SLOT(move()));
    timer->start(25);
*/
}

PacmanGame::~PacmanGame()
{

}
/*
void PacmanGame::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        pacman->setNextDirection(1);
    }else if(event->key() == Qt::Key_D){
        pacman->setNextDirection(2);
    }else if(event->key() == Qt::Key_W){
        pacman->setNextDirection(3);
    }else if(event->key() == Qt::Key_S){
        pacman->setNextDirection(4);
    }else if(event->key() == Qt::Key_Escape){
        QCoreApplication::quit();
    }

    for(int i = 0; i < 4; i++){
        std::cout << this->getPacman()->getAvailableDirections()[i] << "\n\n";
    }
}

void PacmanGame::checkAvailableDirections(){
    //  can it go right

    pacman->setAvailable(2, true);
    for(int i = 0; i < 4; i++){
        if(this->pacman->x() + this->pacman->getWidth() == this->walls[i]->getPosX() && this->pacman->y() + this->pacman->getHeight() > this->walls[i]->getPosY() && this->pacman->y() < this->walls[i]->getPosY() + this->walls[i]->getHeight()){   //  TODO: postaviti da je razlika manja od epsilon
            pacman->setAvailable(2, false);

        }
    }


    //  can it go left

    pacman->setAvailable(1, true);
    for(int i = 0; i < 4; i++){
        if(this->pacman->x() == this->walls[i]->getPosX() + this->walls[i]->getWidth() && this->pacman->y() + this->pacman->getHeight() > this->walls[i]->getPosY() && this->pacman->y() < this->walls[i]->getPosY() + this->walls[i]->getHeight()){   //  TODO: postaviti da je razlika manja od epsilon
            pacman->setAvailable(1, false);

        }
    }

    //  can it go up

    pacman->setAvailable(3, true);
    for(int i = 0; i < 4; i++){
        if(this->pacman->y() == this->walls[i]->getPosY() + this->walls[i]->getHeight() && this->pacman->x() + this->pacman->getWidth() > this->walls[i]->getPosX() && this->pacman->x() < this->walls[i]->getPosX() + this->walls[i]->getWidth()){   //  TODO: postaviti da je razlika manja od epsilon
            pacman->setAvailable(3, false);

        }
    }

    //  can it go down

    pacman->setAvailable(4, true);
    for(int i = 0; i < 4; i++){
        if(this->pacman->y() + this->pacman->getHeight() == this->walls[i]->getPosY() && this->pacman->x() + this->pacman->getWidth() > this->walls[i]->getPosX() && this->pacman->x() < this->walls[i]->getPosX() + this->walls[i]->getWidth()){   //  TODO: postaviti da je razlika manja od epsilon
            pacman->setAvailable(4, false);

        }
    }
}

void PacmanGame::setCurrentDirection(){
    if(pacman->getNextDirection() != 0)
        if(pacman->getAvailableDirections()[pacman->getNextDirection() - 1]){
            pacman->setCurrentDirection(pacman->getNextDirection());
            pacman->setNextDirection(0);
        }

    if(pacman->getCurrentDirection() != 0)
        if(pacman->getAvailableDirections()[pacman->getCurrentDirection()-1] == false)
            pacman->setCurrentDirection(0);

}
*/
Pacman* PacmanGame::getPacman(){
    return this->pacman;
}


int PacmanGame::getWidth(){
    QRect rec = QApplication::desktop()->screenGeometry();
    return rec.width();
}


int PacmanGame::getHeight(){
    QRect rec = QApplication::desktop()->screenGeometry();
    return rec.height();
}



Wall* PacmanGame::getWall(){
    int height = getHeight();
    int width = getWidth();


    QFile mapa{":/new/PacFiles/mapa.txt"};
    mapa.open(QFile::ReadOnly | QFile::Text);
    QTextStream inMap{&mapa};

    char c;


    int i = 0, x = 0, y = 0, broj_duha = 0;
    QChar nula('0');
    QChar kec('1');
    QChar taraba('#');
    //QChar noviRed('\n');

    int spacing = 35;
    Wall *w1;

    while(!inMap.atEnd()){
        inMap >> c;
        if(c == nula)
            x+=spacing;
        else if(c == kec){
            w1 = new Wall(x,y,spacing,spacing);
            this->walls_and_borders.push_back(w1);
            x+=spacing;
            i++; // counts walls
        }
        else if(c == '\n'){
            x = 0;
            y+=spacing;
        }
        else if (c == taraba){
            ++broj_duha;
            this->ghost = new Ghost(x+2,y+2, broj_duha);
            this->ghosts.push_back(ghost);
            x+=spacing;
        }
    }

    return *this->walls;

}

bool add_to_scene(QGraphicsScene &scene, Wall* zid){
    scene.addItem(zid);
    return true;
}

void PacmanGame::populateScene(QGraphicsScene &scene){
    getWall();
    //QGraphicsItemGroup *group = new QGraphicsItemGroup{};

    for(auto x : this->walls_and_borders){
        scene.addItem(x);
        x->setBrush(Qt::darkGray);
    }

    for(auto x : this->ghosts){
        scene.addItem(x);
    }
    /*
    scene = std::accumulate(std::begin(this->walls_and_borders), std::end(this->walls_and_borders),
                    QGraphicsScene, add_to_scene);
    */

}

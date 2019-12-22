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
}

PacmanGame::~PacmanGame()
{

}

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

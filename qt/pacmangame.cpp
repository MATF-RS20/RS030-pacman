#include "pacmangame.h"
#include "globalVariables.h"

#include <iostream>
#include <QDesktopWidget>
#include <QApplication>

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <fstream>
#include <QFile>
#include <fstream>
#include <stdio.h>
#include <QTextStream>
#include <QChar>
#include <list>
#include <numeric>
#include <QString>
#include "dot.h"
#include <QStyleOption>
//#include <pair>

// u global (od globalVariables.h) sam smestio neke promenljive (spacing, nula, bigDot...)
// cisto radi urednosti,
// jos neke sam ideje imao sta sa tim da uradim, ali nisam ih jos razradio
using namespace global;
extern int level_map;

void PacmanGame::setMapSelector(int x)
{
    mapSelector = x;
}

int PacmanGame::getX() const{
    return this->x;
}

int PacmanGame::getY() const{
    return this->y;
}

PacmanGame::PacmanGame(int selectMap, int hearts, int scr)
{
    mapSelector = selectMap;
    health = new Health(hearts);
    score = new Score(0,scr);


/*
    // ingame sounds
    beginning = new QMediaPlayer{};
    beginning->setMedia(QUrl("qrc:/Sounds/pacman_beginning.wav"));

    chomp = new QMediaPlayer{};
    chomp->setMedia(QUrl("qrc:/Sounds/pacman_chomp.wav"));

    eatfruit = new QMediaPlayer{};
    eatfruit->setMedia(QUrl("qrc:/Sounds/pacman_eatfruit.wav"));

    eatghost = new QMediaPlayer{};
    eatghost->setMedia(QUrl("qrc:/Sounds/pacman_eatghost.wav"));

    death = new QMediaPlayer{};
    death->setMedia(QUrl("qrc:/Sounds/pacman_death.wav"));
*/

    int dotNumber = 0;
    std::string mapCe = ":/new/PacFiles/mapa";
    //int mapSelector = 1;                // napravicemo vec neko biranje
    mapCe += std::to_string(mapSelector) + ".txt";
    QString gameMap = QString::fromStdString(mapCe);
    QFile mapa{gameMap};
    mapa.open(QFile::ReadOnly | QFile::Text);
    QTextStream inMap{&mapa};

    char c;


    this->x = 0, this->y = 0;
    int broj_duha = 0;

    int direction;                      // ideja da u fajlu mapa imamo vec odredjen smer pekmena da bismo mogli
                                        // da usmerimo animaciju, taj broj da stoji pre svega ostalog
    inMap >> direction;



    Wall *w1;
    Dot *tuf{};

    inMap >> c;                         // kupi novi red posle ucitanog smera
 //   int pacPosX;
 //   int pacPosY;
    int keepX;

    while(!inMap.atEnd()){
        width++;
        inMap >> c;
        if( (c == nula || c == bigDot) || c==fruit){
            // stavi bobicu, stavimo koliziju pekmena sa
            // bobicom da unisti bobicu i podesi skor
            tuf = new Dot(x,y, c);
            std::pair<int, int> par = {x,y};
            dots[par] = tuf;
            x+=spacing;
            dotNumber++;
        }
        else if(c == kec){
            w1 = new Wall(x,y,spacing,spacing);
            this->walls_and_borders.push_back(w1);
            x+=spacing;
            //i++; // counts walls
        }else if(c == '-'){
            w1 = new Wall(x,y,20,spacing);
            this->walls_and_borders.push_back(w1);
            x+=spacing;
            //i++; // counts walls
        }else if(c == '+'){
            ++broj_duha;
            this->ghost = new Ghost(x+2,y+2, broj_duha);
            this->ghosts.push_back(ghost);
            x+=spacing-13;
            w1 = new Wall(x,y,13,spacing);
            this->walls_and_borders.push_back(w1);
            x+=13;
            //i++; // counts walls
        }
        else if(c == noviRed){
            width--;
            //std::cout << width << "\n";
            keepX = x;
            x = 0;
            y+=spacing;
        }
        else if (c == taraba){
            ++broj_duha;
            this->ghost = new Ghost(x+2,y+2, broj_duha);
            this->ghosts.push_back(ghost);
            x+=spacing;
        }
        else if(c == pacPosition){
            pacPosX = x+2;
            pacPosY = y+2;
            x+=spacing;
        }
        else if(c == emptySpace){
            x+=spacing;
        }
    }
    x = keepX;


    // premesteno ovde da bi u konstruktoru dodali broj bobica koje treba da pojede
    // a broj se povecava u petlji stalno pa mora da se ubaci kad se petlja zavrsi
    this->pacman = new Pacman(pacPosX,pacPosY,dotNumber);
    this->pacman->setCurrentDirection(direction);           // <- ako vas ovaj deo iritira zakomentarisite,
                                                            // stavio sam jer msm da treba da ima


    mapa.close();
}


void PacmanGame::sendGhostsToStartPos()
{
    for(auto x : ghosts)
    {
        x->sendToInitial();
    }
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



bool add_to_scene(QGraphicsScene &scene, Wall* zid){
    scene.addItem(zid);
    return true;
}

void PacmanGame::populateScene(QGraphicsScene &scene){

    for(auto x : this->walls_and_borders){
        scene.addItem(x);
    }

    for(auto x: this->dots){
        scene.addEllipse(x.second->getDot());
    }

    for(auto x : this->ghosts){
        scene.addItem(x);
    }


    scene.addItem(this->pacman);
    scene.addItem(this->score);
    this->health->setPos(health->x() + 155, health->y() + 5);
    this->score->setPos(score->x()+55, score->y() + 5);
    scene.addItem(this->health);

    QGraphicsTextItem *text =  new QGraphicsTextItem(QString("Level: ") + QString::number(level_map));

    text->setPos(text->x()+250, text->y()+5);
    scene.addItem(text);
    scene.update();

    /*
    scene = std::accumulate(std::begin(this->walls_and_borders), std::end(this->walls_and_borders),
                    QGraphicsScene, add_to_scene);
    */

}

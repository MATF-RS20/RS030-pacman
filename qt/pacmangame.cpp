#include "pacmangame.h"

#include <iostream>


PacmanGame::PacmanGame()
{
    this->pacman = new Pacman();
    this->current_score = 0;

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

Wall* PacmanGame::getWall(){
    return *this->walls;
}

void PacmanGame::populateScene(QGraphicsScene &scene){
    scene.addItem(this->walls[0]);
    scene.addItem(this->walls[1]);
    scene.addItem(this->walls[2]);
    scene.addItem(this->walls[3]);
    scene.addItem(this->walls[4]);
    scene.addItem(this->walls[5]);
    scene.addItem(this->walls[6]);
    scene.addItem(this->walls[7]);
    scene.addItem(this->walls[8]);
}

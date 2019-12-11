#include "pacmangame.h"

#include <iostream>


PacmanGame::PacmanGame()
{
    this->pacman = new Character(0, 0, 10, 10, 1366, 768);
    this->current_score = 0;

    Wall *w1 = new Wall(50, 400, 10, 200);
    this->walls[0] = w1;
    Wall *w2 = new Wall(150, 470, 10, 200);
    this->walls[1] = w2;
    Wall *w3 = new Wall(200, 400, 10, 200);
    this->walls[2] = w3;
    Wall *w4 = new Wall(50, 390, 300, 10);
    this->walls[3] = w4;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(checkAvailableDirections()));
    connect(timer, SIGNAL(timeout()), this, SLOT(setCurrentDirection()));
    connect(timer, SIGNAL(timeout()), this->getPacman(), SLOT(move()));
    timer->start(25);
}

PacmanGame::~PacmanGame()
{

}

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

Character* PacmanGame::getPacman(){
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
}

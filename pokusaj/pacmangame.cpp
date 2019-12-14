#include "pacmangame.h"



PacmanGame::PacmanGame()
{
    this->pacman = new Pacman();
    //this->current_score = 0;

    Wall *w1 = new Wall(50, 400, 10, 200);
    this->walls[0] = w1;
    Wall *w2 = new Wall(150, 470, 10, 200);
    this->walls[1] = w2;
    Wall *w3 = new Wall(200, 400, 10, 200);
    this->walls[2] = w3;
    Wall *w4 = new Wall(50, 390, 300, 10);
    this->walls[3] = w4;

    //QTimer *timer = new QTimer(this);
    //connect(timer, SIGNAL(timeout()), this->getPacman(), SLOT(move()));   mislim da ne treba jer pacman ide sa keyPressEvent
    // a duhovi idu sa move() funkcijom
    //timer->start(25);
}

PacmanGame::~PacmanGame()
{}
/*
void PacmanGame::keyPressEvent(QKeyEvent *event)
{
        Pacman::keyPressEvent(&event);

    if(event->key() == Qt::Key_A){ //left
        if (pacman->getX() > 0)
        pacman->setPos(pacman->getX()-10, pacman->getY());
    }else if(event->key() == Qt::Key_D){ //right
        if (pacman->getX() + pacman->getWidth() < pacman->scene()->width())
        pacman->setPos(pacman->getX()+10,pacman->getY());
    }else if(event->key() == Qt::Key_W){ //up
        if(pacman->getY() > 0)
        pacman->setPos(pacman->getX(),pacman->getY()-10);
    }else if(event->key() == Qt::Key_S){ //down
        if(pacman->getY() + pacman->getHeight() < pacman->scene()->height())
        pacman->setPos(pacman->getX(),pacman->getY()+10);
    }else if(event->key() == Qt::Key_Escape){
        QCoreApplication::quit();
    }

}//end of keyPressEvent


void PacmanGame::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){ //left
        if (pacman->getX() > 0)
        pacman->setPos(pacman->getX()-10, pacman->getY());
    }else if(event->key() == Qt::Key_D){ //right
        if (pacman->getX() + pacman->getWidth() < pacman->scene()->width())
        pacman->setPos(pacman->getX()+10,pacman->getY());
    }else if(event->key() == Qt::Key_W){ //up
        if(pacman->getY() > 0)
        pacman->setPos(pacman->getX(),pacman->getY()-10);
    }else if(event->key() == Qt::Key_S){ //down
        if(pacman->getY() + pacman->getHeight() < pacman->scene()->height())
        pacman->setPos(pacman->getX(),pacman->getY()+10);
    }else if(event->key() == Qt::Key_Escape){
        QCoreApplication::quit();
    }

}//end of keyPressEvent

*/

Pacman* PacmanGame::getPacman(){
    return this->pacman;
}

/*
Wall* PacmanGame::getWall(){
    return *this->walls;
}
*/
void PacmanGame::populateScene(QGraphicsScene &scene){
    scene.addItem(this->walls[0]);
    scene.addItem(this->walls[1]);
    scene.addItem(this->walls[2]);
    scene.addItem(this->walls[3]);
}

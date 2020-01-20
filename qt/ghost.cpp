#include "ghost.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h> // rand() - returns a really large int
#include <random>


#include "pacmangame.h"
#include "score.h"
#include "health.h"
#include "game.h"


extern PacmanGame *game1;
extern Game *game;


Ghost::Ghost(int x1, int y1, int id)
    :x1(x1), y1(y1), ghost_id(static_cast<Ghost_Id>(id))
{
    initialX = x1;
    initialY = y1;
    //qDebug() << "Napravljen ghost";
    setPixmap(QPixmap(":/Puck/crveni-gore.png"));
    setTransformOriginPoint(15,15);  // same size as pacman
    setPos(this->x1,this->y1);



    timer = new QTimer(this);
    if (ghost_id == 1){
        setPixmap(QPixmap(":/Puck/crveni-gore.png"));
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(chooseRandom()));

        timer->start(4800);

        timerM = new QTimer(this);
        QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move1()));
        timerM->start(25);

    }else if (ghost_id == 2){
        setPixmap(QPixmap(":/Puck/zeleni-gore.png"));
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(chooseRandom()));

        timer->start(4800);


        timerM = new QTimer(this);
        QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move1()));
        timerM->start(25);

    }else if (ghost_id == 3){
        setPixmap(QPixmap(":/Puck/plavi-gore.png"));
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(chooseRandom()));

        timer->start(4800);


        timerM = new QTimer(this);
        QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move1()));
        timerM->start(25);

    }else if (ghost_id == 4){
        setPixmap(QPixmap(":/Puck/zuti-gore.png"));
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(chooseRandom()));

        timer->start(4800);


        timerM = new QTimer(this);
        QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move1()));
        timerM->start(25);

    }

}

void Ghost::sendToInitial()
{
    x1 = initialX;
    y1 = initialY;
    this->setPos(x1,y1);
}

void Ghost::chooseRandom() {


    if (game->game1->flag ==1){
        this->timer->stop();
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,4);
    this->nextDirection = dis(gen);

}





void Ghost::move1()
{

    if (game->game1->flag ==1){
        this->timerM->stop();
        return;
    }

    if(!game->game1->pojedi && game->game1->getPacman()->lc%2 != 1){
        if (ghost_id == 1){
                if (this->currentDirection == 1){
                    setPixmap(QPixmap(":/Puck/crveni-levo.png"));
                }else if (this->currentDirection == 2)
                    setPixmap(QPixmap(":/Puck/crveni-desno.png"));
                else if (this->currentDirection == 3)
                    setPixmap(QPixmap(":/Puck/crveni-gore.png"));
                else if (this->currentDirection == 4)
                    setPixmap(QPixmap(":/Puck/crveni-dole.png"));
        }
        if (ghost_id == 2){
                if (this->currentDirection == 1){
                    setPixmap(QPixmap(":/Puck/zeleni-levo.png"));
                }else if (this->currentDirection == 2)
                    setPixmap(QPixmap(":/Puck/zeleni-desno.png"));
                else if (this->currentDirection == 3)
                    setPixmap(QPixmap(":/Puck/zeleni-gore.png"));
                else if (this->currentDirection == 4)
                    setPixmap(QPixmap(":/Puck/zeleni-dole.png"));
        }
        if (ghost_id == 3){
                if (this->currentDirection == 1){
                    setPixmap(QPixmap(":/Puck/plavi-levo.png"));
                }else if (this->currentDirection == 2)
                    setPixmap(QPixmap(":/Puck/plavi-desno.png"));
                else if (this->currentDirection == 3)
                    setPixmap(QPixmap(":/Puck/plavi-gore.png"));
                else if (this->currentDirection == 4)
                    setPixmap(QPixmap(":/Puck/plavi-dole.png"));
        }
        if (ghost_id == 4){
                if (this->currentDirection == 1){
                    setPixmap(QPixmap(":/Puck/zuti-levo.png"));
                }else if (this->currentDirection == 2)
                    setPixmap(QPixmap(":/Puck/zuti-desno.png"));
                else if (this->currentDirection == 3)
                    setPixmap(QPixmap(":/Puck/zuti-gore.png"));
                else if (this->currentDirection == 4)
                    setPixmap(QPixmap(":/Puck/zuti-dole.png"));
        }
    } else {
        setPixmap(QPixmap(":/Puck/duh-jedi.png"));
    }

    if (this->nextDirection != 0)
    {
        if (this->nextDirection == 1)
            setPos(getX() - 3, getY());
        else if (this->nextDirection == 2)
            setPos(getX() + 3, getY());
        else if (this->nextDirection == 3)
            setPos(getX(), getY() - 3);
        else if (this->nextDirection == 4)
            setPos(getX(), getY() + 3);

        // pokusas sa next
        // ako ima kolizije korak unazad
        // i nastavis sa current
        // ako nema kolizije super stavis da current bude next a next da bude nula

        // vraca listu objkekata sa kojim je u koliziji
        // ako lista nije prazna onda korak unazad
        QList<QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        for(auto x: colliding_items){
            if(x->boundingRect().size().rwidth() == 13 || x->boundingRect().size().rwidth() == 5 || x->boundingRect().size().rwidth() == 11 || x->boundingRect().size().rwidth() == 20 || x->boundingRect().size().rwidth() == 31){
                n--;
            }
            //else if(x->boundingRect().size().rwidth() == this->boundingRect().rwidth())

        }
        if (n != 0)
        {
                if(((game->game1->getPacman()->lc > 0 &&  game->game1->getPacman()->lc < 11) || game->game1->pojedi) && colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                    this->sendToInitial();
                    game->game1->score->setScore(200);
                }else if(colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                    game->game1->score->setScore(-50);
                    game->game1->health->decrease();
                if (game->game1->health->getHealth() == 0){
                    game->game1->flag = 1;
                    QString message = "You lost :(";
                    game->gameOver(message);
                    std::cout << "VISE SRECE DRUGIT PUT!!!\n";

                }
                else{

                    //=======SEND THEM HOME============
                    game->game1->sendGhostsToStartPos();

                    game->game1->getPacman()->setPos(game->game1->pacPosX,game->game1->pacPosY);
                }
            }

            if (this->nextDirection == 1)
                setPos(getX() + 3, getY());
            else if (this->nextDirection == 2)
                setPos(getX() - 3, getY());
            else if (this->nextDirection == 3)
                setPos(getX(), getY() + 3);
            else if (this->nextDirection == 4)
                setPos(getX(), getY() - 3);

            if (this->currentDirection == 1)
                setPos(getX() - 3, getY());
            else if (this->currentDirection == 2)
                setPos(getX() + 3, getY());
            else if (this->currentDirection == 3)
                setPos(getX(), getY() - 3);
            else if (this->currentDirection == 4)
                setPos(getX(), getY() + 3);
            colliding_items = collidingItems();
            int n = colliding_items.size();
            for(auto x: colliding_items){
                if(x->boundingRect().size().rwidth() == 13 || x->boundingRect().size().rwidth() == 5 || x->boundingRect().size().rwidth() == 11 || x->boundingRect().size().rwidth() == 20 || x->boundingRect().size().rwidth() == 31){
                    n--;
                }

            }
            if (n != 0)
            {
                if(((game->game1->getPacman()->lc > 0 &&  game->game1->getPacman()->lc < 11) || game->game1->pojedi) && colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                    this->sendToInitial();
                    game->game1->score->setScore(200);
                }else if(colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                    //  game1->health->decrease();
                      game->game1->health->decrease();
                      game->game1->score->setScore(-50);
                    if (game->game1->health->getHealth() == 0){
                        game->game1->flag = 1;
                        QString message = "You lost :(";
                        game->gameOver(message);
                        std::cout << "VISE SRECE DRUGIT PUT!!!\n";
                        //QCoreApplication::quit();
                    }
                    else{
                          //=======SEND THEM HOME============
                          game->game1->sendGhostsToStartPos();

                          game->game1->getPacman()->setPos(game->game1->pacPosX,game->game1->pacPosY);
                    }
                }
                // ako ima kolizije unazad
                if (this->currentDirection == 1)
                    setPos(getX() + 3, getY());
                else if (this->currentDirection == 2)
                    setPos(getX() - 3, getY());
                else if (this->currentDirection == 3)
                    setPos(getX(), getY() + 3);
                else if (this->currentDirection == 4)
                    setPos(getX(), getY() - 3);

                this->currentDirection = 0;
            }
        }
        else
        {
            //ako je sve uredu staviti trenutnu poziciju na sledecu
            this->currentDirection = this->nextDirection;
            this->nextDirection = 0;
        }
    }
    else
    { // ako next ne postoji samo radi normalno
        if (this->currentDirection == 1)
            setPos(getX() - 3, getY());
        else if (this->currentDirection == 2)
            setPos(getX() + 3, getY());
        else if (this->currentDirection == 3)
            setPos(getX(), getY() - 3);
        else if (this->currentDirection == 4)
            setPos(getX(), getY() + 3);
        QList<QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        for(auto x: colliding_items){
            if(x->boundingRect().size().rwidth() == 13 || x->boundingRect().size().rwidth() == 5 || x->boundingRect().size().rwidth() == 11 || x->boundingRect().size().rwidth() == 20 || x->boundingRect().size().rwidth() == 31){
                n--;
            }

        }
        if (n != 0)
        {
            if(((game->game1->getPacman()->lc > 0 &&  game->game1->getPacman()->lc < 11) || game->game1->pojedi) && colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                this->sendToInitial();
                game->game1->score->setScore(200);
            }else if(colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                //game1->health->decrease();
                game->game1->health->decrease();
                game->game1->score->setScore(-50);
                if (game->game1->health->getHealth() == 0){
                    game->game1->flag = 1;
                    QString message = "You lost :(";
                    game->gameOver(message);
                    std::cout << "VISE SRECE DRUGIT PUT!!!\n";

                }
                else {
                    //=======SEND THEM HOME============
                    game->game1->sendGhostsToStartPos();

                    game->game1->getPacman()->setPos(game->game1->pacPosX,game->game1->pacPosY);
                }
            }
            // ako ima kolizije unazad
            if (this->currentDirection == 1)
                setPos(getX() + 3, getY());
            else if (this->currentDirection == 2)
                setPos(getX() - 3, getY());
            else if (this->currentDirection == 3)
                setPos(getX(), getY() + 3);
            else if (this->currentDirection == 4)
                setPos(getX(), getY() - 3);

            this->currentDirection = 0;
        }
    }

    if (getX() < -this->boundingRect().size().rwidth())
        setPos(this->scene()->width(), getY());
    if (getY() < 3)
        setPos(getX(), 3);
    if (getX() > this->scene()->width())
        setPos(- this->boundingRect().size().rwidth() - 1, getY());
    if (getY() > this->scene()->height() - this->boundingRect().size().rheight() - 3)
        setPos(getX(), this->scene()->height() - this->boundingRect().size().rheight() - 3);



    if (this->currentDirection == 0) chooseRandom();
}
int Ghost::getX()  {return this->x();}
int Ghost::getY()  {return this->y();}


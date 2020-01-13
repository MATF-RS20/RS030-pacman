#include "ghost.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h> // rand() - returns a really large int
#include <random>


#include "pacmangame.h"
#include "score.h"
#include "health.h"

extern PacmanGame *game1;


Ghost::Ghost(int x1, int y1, int id)
    :x1(x1), y1(y1), ghost_id(static_cast<Ghost_Id>(id))
{
    qDebug() << "Napravljen ghost";
    setRect(0, 0, 30,30);  // same size as pacman
    setPos(this->x1,this->y1);
    //this->scene()->addItem(this);





    // Stavio sam sve tajmere na move1() samo da vidim kako bi izgledalo
    // posto je to jedini random








    QTimer *timer = new QTimer(this);
    if (ghost_id == 1){     //random
        this->setBrush(Qt::red);
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(chooseRandom()));

        timer->start(4800);


        QTimer *timerM = new QTimer(this);
        QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move1()));
        timerM->start(25);


    }else if (ghost_id == 2){   //chaser - manhattan algorithm    ovako reba da bude samo algoritam da provalim
        this->setBrush(Qt::green);
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(chooseRandom()));

        //qDebug() << nextDirection;
        timer->start(4800);


        QTimer *timerM = new QTimer(this);
        QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move1()));
        timerM->start(25);

    }else if (ghost_id == 3){
        this->setBrush(Qt::black);
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(chooseRandom()));

        timer->start(4800);


        QTimer *timerM = new QTimer(this);
        QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move1()));
        timerM->start(25);

    }else if (ghost_id == 4){
        this->setBrush(Qt::darkYellow);
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(chooseRandom()));

        timer->start(4800);


        QTimer *timerM = new QTimer(this);
        QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move1()));
        timerM->start(25);

    }

}

void Ghost::chooseRandom() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,4);
    this->nextDirection = dis(gen);
/*
    qDebug() << "id " << this->ghost_id << "\n";
    qDebug() << "next " << this->nextDirection << "\n";
    qDebug() << "current" << this->currentDirection << "\n\n";*/
}





void Ghost::move1()
{
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
            if(x->boundingRect().size().rwidth() == 5 || x->boundingRect().size().rwidth() == 11 || x->boundingRect().size().rwidth() == 20){
                n--;
            }
            //else if(x->boundingRect().size().rwidth() == this->boundingRect().rwidth())

        }
        if (n != 0)
        {
            if(colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                //game1->health->decrease();
                if (game1->health->getHealth() == 0){
                    std::cout << "VISE SRECE DRUGIT PT!!!\n";
                    QCoreApplication::quit();
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
                if(x->boundingRect().size().rwidth() == 5 || x->boundingRect().size().rwidth() == 11 || x->boundingRect().size().rwidth() == 20){
                    n--;
                }

            }
            if (n != 0)
            {
                if(colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                  //  game1->health->decrease();
                    if (game1->health->getHealth() == 0){
                        std::cout << "VISE SRECE DRUGIT PT!!!\n";
                        QCoreApplication::quit();
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
            if(x->boundingRect().size().rwidth() == 5 || x->boundingRect().size().rwidth() == 11 || x->boundingRect().size().rwidth() == 20){
                n--;
            }

        }
        if (n != 0)
        {
            if(colliding_items[0]->boundingRect().size().rwidth() + 1 == this->boundingRect().size().rwidth()){
                //game1->health->decrease();
                if (game1->health->getHealth() == 0){
                    std::cout << "VISE SRECE DRUGIT PT!!!\n";
                    QCoreApplication::quit();
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


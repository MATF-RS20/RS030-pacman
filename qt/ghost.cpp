#include "ghost.h"
#include <QTimer>
#include <QDebug>
#include <stdlib.h> // rand() - returns a really large int
#include <random>


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
    if (ghost_id == 1){
        this->setBrush(Qt::red);
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(move1()));

    }else if (ghost_id == 2){
        this->setBrush(Qt::green);
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0,4);
        this->nextDirection = dis(gen);
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(move1()));

        qDebug() << nextDirection;
    }else if (ghost_id == 3){
        this->setBrush(Qt::black);
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(move1()));
    }else if (ghost_id == 4){
        this->setBrush(Qt::darkYellow);
        QObject::connect(timer,SIGNAL(timeout()), this, SLOT(move1()));
    }
    timer->start(4800);


    QTimer *timerM = new QTimer(this);
    QObject::connect(timerM,SIGNAL(timeout()), this, SLOT(move()));
    timerM->start(25);

}

void Ghost::move1() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,4);
    this->nextDirection = dis(gen);

    qDebug() << "id " << this->ghost_id << "\n";
    qDebug() << "next " << this->nextDirection << "\n";
    qDebug() << "current" << this->currentDirection << "\n\n";
}




void Ghost::move2(){
    // ideja
    // 4 duha 4 razlicita kretanja i kretanje da zavisi od id-ja koji ce dobiti svaki duh i koji je unikatan
    // za sada ovako
    // plus treba dodati ako udari o zid menja pravac



    // 1 - left; 2 - right; 3 - up; 4 - down; 0 - none


        if (this->nextDirection == 1)
            setPos(this->x() - 5, this->y());
        else if (this->nextDirection == 2)
            setPos(this->x() + 5, this->y());
        else if (this->nextDirection == 3){
            setPos(this->x(), this->y() - 5);
            qDebug() << "Krenula ka gore";
        }
        else if (this->nextDirection == 4)
            setPos(this->x(), y() + 5);

    /*if (this->nextDirection != 0)
    {
        if (this->nextDirection == 1)
            setPos(this->x - 5, this->y);
        else if (this->nextDirection == 2)
            setPos(this->x + 5, this->y);
        else if (this->nextDirection == 3){
            setPos(this->x, this->y - 5);
            qDebug() << "Krenula ka gore";
        }
        else if (this->nextDirection == 4)
            setPos(this->x, y + 5);

        //qDebug() << "Prvo nexDirection";
        // pokusas sa next
        // ako ima kolizije korak unazad
        // i nastavis sa current
        // ako nema kolizije super stavis da current bude next a next da bude nula

        // vraca listu objkekata sa kojim je u koliziji
        // ako lista nije prazna onda korak unazad
        QList<QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        //qDebug() << "Prva kolizija";
        if (n != 0)
        {
            if (this->nextDirection == 1)
                setPos(x + 5, y);
            else if (this->nextDirection == 2)
                setPos(x - 5, y);
            else if (this->nextDirection == 3)
                setPos(x, y + 5);
            else if (this->nextDirection == 4)
                setPos(x, y - 5);

            if (this->currentDirection == 1)
                setPos(x - 5, y);
            else if (this->currentDirection == 2)
                setPos(x + 5, y);
            else if (this->currentDirection == 3)
                setPos(x, y - 5);
            else if (this->currentDirection == 4)
                setPos(x, y + 5);
            colliding_items = collidingItems();
            int n = colliding_items.size();
            //qDebug() << "Druga kolizija";
            if (n != 0)
            {
                // ako ima kolizije unazad
                if (this->currentDirection == 1)
                    setPos(x + 5, y);
                else if (this->currentDirection == 2)
                    setPos(x - 5, y);
                else if (this->currentDirection == 3)
                    setPos(x, y + 5);
                else if (this->currentDirection == 4)
                    setPos(x, y - 5);
            }
        }
        else
        {
            //qDebug() << "Nije uslo u if drugi put, tj posle prve kolizije";
            //ako je sve uredu staviti trenutnu poziciju na sledecu
            this->currentDirection = this->nextDirection;
            this->nextDirection = 0;
        }
    }
    else
    { // ako next ne postoji samo radi normalno
        qDebug() << "nexDirection == 0 prvi put";
        if (this->currentDirection == 1)
            setPos(x - 5, y);
        else if (this->currentDirection == 2)
            setPos(x + 5, y);
        else if (this->currentDirection == 3)
            setPos(x, y - 5);
        else if (this->currentDirection == 4)
            setPos(x, y + 5);
        QList<QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        if (n != 0)
        {
            // ako ima kolizije unazad
            if (this->currentDirection == 1)
                setPos(x + 5, y);
            else if (this->currentDirection == 2)
                setPos(x - 5, y);
            else if (this->currentDirection == 3)
                setPos(x, y + 5);
            else if (this->currentDirection == 4)
                setPos(x, y - 5);
        }
    }

    if (x < -this->boundingRect().size().rwidth())
        setPos(this->scene()->width(), y);
    if (y < 3)
        setPos(x, 3);
    if (x > this->scene()->width())
        setPos(- this->boundingRect().size().rwidth(), y);
    if (y > this->scene()->height() - this->boundingRect().size().rheight() - 3)
        setPos(x, this->scene()->height() - this->boundingRect().size().rheight() - 3);

    } */
  //  this->nextDirection = rand() % 5;

   }



void Ghost::move3() {
    setPos(this->x(), this->y() + 5);
}



void Ghost::move4() {
    setPos(this->x() + 5, this->y());
}

void Ghost::move()
{
    if (this->nextDirection != 0)
    {
        if (this->nextDirection == 1)
            setPos(getX() - 5, getY());
        else if (this->nextDirection == 2)
            setPos(getX() + 5, getY());
        else if (this->nextDirection == 3)
            setPos(getX(), getY() - 5);
        else if (this->nextDirection == 4)
            setPos(getX(), getY() + 5);

        // pokusas sa next
        // ako ima kolizije korak unazad
        // i nastavis sa current
        // ako nema kolizije super stavis da current bude next a next da bude nula

        // vraca listu objkekata sa kojim je u koliziji
        // ako lista nije prazna onda korak unazad
        QList<QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        if (n != 0)
        {
            if (this->nextDirection == 1)
                setPos(getX() + 5, getY());
            else if (this->nextDirection == 2)
                setPos(getX() - 5, getY());
            else if (this->nextDirection == 3)
                setPos(getX(), getY() + 5);
            else if (this->nextDirection == 4)
                setPos(getX(), getY() - 5);

            if (this->currentDirection == 1)
                setPos(getX() - 5, getY());
            else if (this->currentDirection == 2)
                setPos(getX() + 5, getY());
            else if (this->currentDirection == 3)
                setPos(getX(), getY() - 5);
            else if (this->currentDirection == 4)
                setPos(getX(), getY() + 5);
            colliding_items = collidingItems();
            int n = colliding_items.size();
            if (n != 0)
            {
                // ako ima kolizije unazad
                if (this->currentDirection == 1)
                    setPos(getX() + 5, getY());
                else if (this->currentDirection == 2)
                    setPos(getX() - 5, getY());
                else if (this->currentDirection == 3)
                    setPos(getX(), getY() + 5);
                else if (this->currentDirection == 4)
                    setPos(getX(), getY() - 5);

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
            setPos(getX() - 5, getY());
        else if (this->currentDirection == 2)
            setPos(getX() + 5, getY());
        else if (this->currentDirection == 3)
            setPos(getX(), getY() - 5);
        else if (this->currentDirection == 4)
            setPos(getX(), getY() + 5);
        QList<QGraphicsItem *> colliding_items = collidingItems();
        int n = colliding_items.size();
        if (n != 0)
        {
            // ako ima kolizije unazad
            if (this->currentDirection == 1)
                setPos(getX() + 5, getY());
            else if (this->currentDirection == 2)
                setPos(getX() - 5, getY());
            else if (this->currentDirection == 3)
                setPos(getX(), getY() + 5);
            else if (this->currentDirection == 4)
                setPos(getX(), getY() - 5);

            this->currentDirection = 0;
        }
    }

    if (getX() < -this->boundingRect().size().rwidth())
        setPos(this->scene()->width(), getY());
    if (getY() < 3)
        setPos(getX(), 3);
    if (getX() > this->scene()->width())
        setPos(- this->boundingRect().size().rwidth(), getY());
    if (getY() > this->scene()->height() - this->boundingRect().size().rheight() - 3)
        setPos(getX(), this->scene()->height() - this->boundingRect().size().rheight() - 3);



    if (this->currentDirection == 0) move1();
}
int Ghost::getX()  {return this->x();}
int Ghost::getY()  {return this->y();}

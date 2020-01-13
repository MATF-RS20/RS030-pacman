#include "pacman.h"
//#include "globalVariables.h"
#include <QUrl>
#include "pacmangame.h"
#include "score.h"
#include "health.h"

extern PacmanGame *game1;

Pacman::Pacman(int x1, int y1, int dotsInMap)
    :x1(x1),y1(y1),dotsToEat(dotsInMap)
{
    setRect(0, 0, 29, 29);
    setPos(this->x1,this->y1);
    eatenDots = 0;

    this->setBrush(Qt::yellow);

    this->current_score = 0;

    /*
    // ingame sounds
    beginning = new QMediaPlayer{};
    beginning->setMedia(QUrl("qrc:/Sounds/pacman_beginning.wav"));

    chomp = new QMediaPlayer{};
    chomp->setMedia(QUrl(":/Sounds/pacman_chomp.wav"));

    eatfruit = new QMediaPlayer{};
    eatfruit->setMedia(QUrl(":/Sounds/pacman_eatfruit.wav"));

    eatghost = new QMediaPlayer{};
    eatghost->setMedia(QUrl(":/Sounds/pacman_eatghost.wav"));

    death = new QMediaPlayer{};
    death->setMedia(QUrl(":/Sounds/pacman_death.wav"));
    //
    */

    QTimer *timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(25);
}


int Pacman::getX() {return this->x(); }
int Pacman::getY(){ return this->y(); }


void Pacman::keyPressEvent(QKeyEvent *event)
{
    //treba u meni-ju korisnik da izabere da li ce da se krece na strelicu ili na jkli.. za sada ovako

    // **Micovic je mislio na hjkl, slova koja se koriste za pomeranje pozicije u vim-u

    //kolizija sa Ghost-om

    if (event->key() == Qt::Key_Left)
    {
        this->nextDirection = 1;
    }
    else if (event->key() == Qt::Key_Right)
    {
        this->nextDirection = 2;
    }
    else if (event->key() == Qt::Key_Up)
    {
        this->nextDirection = 3;
    }
    else if (event->key() == Qt::Key_Down)
    {
        this->nextDirection = 4;
    }
    else if (event->key() == Qt::Key_H)
    { // left
        this->nextDirection = 1;
    }
    else if (event->key() == Qt::Key_L)
    { //right
        this->nextDirection = 2;
    }
    else if (event->key() == Qt::Key_K)
    { // up
        this->nextDirection = 3;
    }
    else if (event->key() == Qt::Key_J)
    { //down
        this->nextDirection = 4;
    }
    else if (event->key() == Qt::Key_Escape)
    {
        qDebug() << "IZLAAAZ";
        QCoreApplication::quit();
    }
}

void Pacman::move()
{
    if(this->eatenDots == this->dotsToEat){
        std::cout << "CESTITAM!!!\n";
        QCoreApplication::quit();
    }

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
        for(auto x: colliding_items){
            if(x->boundingRect().size().rwidth() == 5){
                scene()->removeItem(x);
                //global::allDots.erase(x);
                delete x;
                scene()->update();
                this->eatenDots++;
                //std::cout<< this->eatenDots << " : " << this->dotsToEat<<std::endl;
                game1->score->setScore(20);
                //=======================
                this->current_score +=20;

            }else if(x->boundingRect().size().rwidth() == 11){
                scene()->removeItem(x);
                //global::allDots.erase(x);
                delete x;
                scene()->update();
                this->eatenDots++;
                //std::cout<< this->eatenDots << " : " << this->dotsToEat<<std::endl;
            }else if(x->boundingRect().size().rwidth() == 20){
                scene()->removeItem(x);
                game1->score->setScore(20);
                //===================
                this->current_score +=20;
                //global::allDots.erase(x);
                delete x;
                scene()->update();
                this->eatenDots++;
                //std::cout<< this->eatenDots << " : " << this->dotsToEat<<std::endl;
            }else if(x->boundingRect().size().rwidth() - 1 == this->boundingRect().size().rwidth()){
                game1->health->decrease();
                if (game1->health == 0){
                    std::cout << "VISE SRECE DRUGIT PT!!!\n";
                    QCoreApplication::quit();
                }

            }
        }

            //qDebug() << n <<"\n";

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
            for(auto x: colliding_items){
                if(x->boundingRect().size().rwidth() == 5){
                    this->eatenDots++;
                    scene()->removeItem(x);
                    delete x;
                    scene()->update();
                    n--;
                    game1->score->setScore(20);
                    //======================
                    this->current_score +=20;

                }else if(x->boundingRect().size().rwidth() == 11){
                    this->eatenDots++;
                    scene()->removeItem(x);
                    delete x;
                    scene()->update();
                    n--;
                }else if(x->boundingRect().size().rwidth() == 20){
                    this->eatenDots++;
                    scene()->removeItem(x);
                    delete x;
                    scene()->update();
                    n--;
                    game1->score->setScore(20);
                    //=========================
                    this->current_score +=20;
                }else if(x->boundingRect().size().rwidth() - 1 == this->boundingRect().size().rwidth()){
                    game1->health->decrease();
                    if (game1->health == 0){
                        std::cout << "VISE SRECE DRUGIT PT!!!\n";
                        QCoreApplication::quit();
                    }

                }

            }
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
            }
        }
        else
        {
            //ako je sve uredu staviti trenutnu poziciju na sledecu
            this->currentDirection = this->nextDirection;
            this->nextDirection = 0;
        }
        //qDebug() << n <<"\n";
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

        for(auto x: colliding_items){
            if(x->boundingRect().size().rwidth() == 5){
                this->eatenDots++;
                scene()->removeItem(x);
                delete x;
                scene()->update();
                game1->score->setScore(20);
                //======================
                this->current_score +=20;
            }else if(x->boundingRect().size().rwidth() == 11){
                this->eatenDots++;
                scene()->removeItem(x);
                delete x;
                scene()->update();
            }else if(x->boundingRect().size().rwidth() == 20){
                this->eatenDots++;
                scene()->removeItem(x);
                delete x;
                scene()->update();
                game1->score->setScore(20);
                //=======================
                this->current_score += 20;
            }else if(x->boundingRect().size().rwidth() == this->boundingRect().size().rwidth()){
                game1->health->decrease();
                if (game1->health == 0){
                    std::cout << "VISE SRECE DRUGIT PT!!!\n";
                    QCoreApplication::quit();
                }

            }

        }

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
        }
    }

    if (getX() < -this->boundingRect().size().rwidth())
        setPos(this->scene()->width(), getY());
    if (getY() < 3)
        setPos(getX(), 3);
    if (getX() > this->scene()->width())
        setPos(- this->boundingRect().size().rwidth()-1, getY());
    if (getY() > this->scene()->height() - this->boundingRect().size().rheight() - 3)
        setPos(getX(), this->scene()->height() - this->boundingRect().size().rheight() - 3);

}


void Pacman::setCurrentDirection(int x)
{
    this->currentDirection = x%5;
}

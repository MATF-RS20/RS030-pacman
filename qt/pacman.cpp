#include "pacman.h"
//#include "globalVariables.h"
#include <QUrl>
#include "pacmangame.h"
#include "score.h"
#include "health.h"

#include "game.h"

#include <fstream>

extern PacmanGame *game1;
extern Game * game;
extern int level_map;

Pacman::Pacman(int x1, int y1, int dotsInMap)
    :x1(x1),y1(y1),dotsToEat(dotsInMap)
{
    //setRect(0, 0, 29, 29);
    setPixmap(QPixmap(":/Puck/pacman1.jpg"));
    setTransformOriginPoint(15,15);
    setPos(this->x1,this->y1);
    eatenDots = 0;


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
    connect(timerLastChance, SIGNAL(timeout()), this, SLOT(last_chance()));

    QTimer *timer1 = new QTimer(this);

    connect(timer1, SIGNAL(timeout()), this, SLOT(animation()));// i korektivni_faktor

    timer1->start(150);

    connect(timer_jedi, SIGNAL(timeout()), this, SLOT(jedi()));// i korektivni_faktor


}


int Pacman::getX() {return this->x(); }
int Pacman::getY(){ return this->y(); }


void Pacman::keyPressEvent(QKeyEvent *event)
{

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
int i3 = 0;
void Pacman::animation(){
    if(i3 == 0)
        setPixmap(QPixmap(":/Puck/pacman-otvoren.png"));
    if(i3 == 1)
        setPixmap(QPixmap(":/Puck/pacman-polu.png"));
    if(i3 == 2)
        setPixmap(QPixmap(":/Puck/pacman-zatvoren.png"));

    scene()->update();
    i3 = (i3 + 1)%3;
    korektivni_faktor -= 0.001;
}
void Pacman::jedi(){
    if(!game->game1->pojedi){
        timer_jedi->stop();
        return;
    }
    lc = 0;
    timerLastChance->start(150);
    game->game1->pojedi = false;
}
void Pacman::last_chance(){
    if(lc == 11){
        timerLastChance->stop();

    }
    lc++;
}
void Pacman::move()
{
    if (this->currentDirection == 1)
        setRotation(180);
    else if (this->currentDirection == 2)
        setRotation(0);
    else if (this->currentDirection == 3)
        setRotation(270);
    else if (this->currentDirection == 4)
        setRotation(90);


// OVDE--------------------------
    if(this->eatenDots == this->dotsToEat && level_map == 4){
        QString message = "Congratulations";
        //QApplication::quit();

        //=========STOP THE PUCK HEW GONE NUTS BRUH=================
        // tj, svi se ukoce sem njega u bilo kom scenariju, nz kako da ga zaustavum
        //=========HIS POWER LEVEL IS OFF THE CHARTS BOIII==========
        this->setDirs0();
        game->game1->flag = 1;
        game->gameOver(message);
        std::cout << "CESTITAM!!!\n";
        this->eatenDots = 0;

    } else if (this->eatenDots == this->dotsToEat){
        this->setDirs0();
        game->game1->flag = 1;
       level_map =(level_map + 1)%5;
        std::cout << "level je "<< level_map <<"\n";
       //sledeci nivo
       game->again();
       this->eatenDots = 0;
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
                game->game1->score->setScore(5*korektivni_faktor);
                n--;
                //=======================
                this->current_score +=5;

            }else if(x->boundingRect().size().rwidth() == 11){
                scene()->removeItem(x);
                //global::allDots.erase(x);
                delete x;
                scene()->update();
                this->eatenDots++;
                game->game1->score->setScore(20*korektivni_faktor);
                game->game1->pojedi = true;
                timer_jedi->start(7000);
                n--;
                //=======================
                this->current_score +=20*korektivni_faktor;
                //std::cout<< this->eatenDots << " : " << this->dotsToEat<<std::endl;
            }else if(x->boundingRect().size().rwidth() == 20){
                scene()->removeItem(x);
                game->game1->score->setScore(100*korektivni_faktor);
                //===================
                this->current_score +=100*korektivni_faktor;
                //global::allDots.erase(x);
                delete x;
                scene()->update();
                n--;
                this->eatenDots++;
                //std::cout<< this->eatenDots << " : " << this->dotsToEat<<std::endl;
            }else if(((lc > 0 && lc < 11) || game->game1->pojedi) && x->boundingRect().size().rwidth() - 1 == this->boundingRect().size().rwidth()){
                //game->game1->sendGhostsToStartPos();
                x->boundingRect().size().rwidth() -= 2;
                for(auto a: game->game1->ghosts){
                    if(a->boundingRect().size().rwidth() == x->boundingRect().size().rwidth() - 3)
                        a->sendToInitial();
                }
                x->boundingRect().size().rwidth() += 2;
                n--;
                game->game1->score->setScore(200*korektivni_faktor);
            }else if(x->boundingRect().size().rwidth() - 1 == this->boundingRect().size().rwidth()){
                game->game1->health->decrease();
                if (game->game1->health->getHealth() == 0){
                    this->setDirs0();
                    game->game1->flag = 1;
                    QString message = "You lost :(";
                    game->gameOver(message);
                    std::cout << "VISE SRECE DRUGIT PUT!!!\n";
                    //QCoreApplication::quit();
                    return;
                }
                else {
                    //game->game1->health->decrease();
                    game->game1->sendGhostsToStartPos();
                    setPos(game->game1->pacPosX,game->game1->pacPosY);
                    return;
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
                    game->game1->score->setScore(5*korektivni_faktor);
                    //======================
                    this->current_score +=5*korektivni_faktor;

                }else if(x->boundingRect().size().rwidth() == 11){
                    this->eatenDots++;
                    scene()->removeItem(x);
                    delete x;
                    game->game1->pojedi = true;
                    timer_jedi->start(7000);
                    scene()->update();
                    n--;
                    game->game1->score->setScore(20*korektivni_faktor);
                    //======================
                    this->current_score +=20*korektivni_faktor;
                }else if(x->boundingRect().size().rwidth() == 20){
                    this->eatenDots++;
                    scene()->removeItem(x);
                    delete x;
                    scene()->update();
                    n--;
                    game->game1->score->setScore(100*korektivni_faktor);
                    //=========================
                    this->current_score +=100*korektivni_faktor;
                }else if(((lc > 0 && lc < 11) || game->game1->pojedi) && x->boundingRect().size().rwidth() - 1 == this->boundingRect().size().rwidth()){
                    //game->game1->sendGhostsToStartPos();
                    x->boundingRect().size().rwidth() -= 2;
                    for(auto a: game->game1->ghosts){
                        if(a->boundingRect().size().rwidth() == x->boundingRect().size().rwidth() - 3)
                            a->sendToInitial();
                    }
                    x->boundingRect().size().rwidth() += 2;
                    n--;
                    game->game1->score->setScore(200*korektivni_faktor);
                }else if(x->boundingRect().size().rwidth() - 1 == this->boundingRect().size().rwidth()){
                    game->game1->health->decrease();
                    if (game->game1->health->getHealth() == 0){
                        this->setDirs0();
                        game->game1->flag = 1;
                        QString message = "You lost :(";
                        game->gameOver(message);
                        std::cout << "VISE SRECE DRUGIT PUT!!!\n";
                        //QCoreApplication::quit();
                        return;
                    }
                    else {

                        game->game1->sendGhostsToStartPos();
                        setPos(game->game1->pacPosX,game->game1->pacPosY);
                        return;
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
                game->game1->score->setScore(5*korektivni_faktor);
                n--;
                //======================
                this->current_score +=5*korektivni_faktor;
            }else if(x->boundingRect().size().rwidth() == 11){
                this->eatenDots++;
                scene()->removeItem(x);
                delete x;
                game->game1->pojedi = true;
                timer_jedi->start(7000);
                scene()->update();
                game->game1->score->setScore(20*korektivni_faktor);
                n--;
                //=======================
                this->current_score += 20*korektivni_faktor;
            }else if(x->boundingRect().size().rwidth() == 20){
                this->eatenDots++;
                scene()->removeItem(x);
                delete x;
                scene()->update();
                game->game1->score->setScore(100*korektivni_faktor);
                n--;
                //=======================
                this->current_score += 100*korektivni_faktor;
            }else if(((lc > 0 && lc < 11) || game->game1->pojedi) && x->boundingRect().size().rwidth() - 1 == this->boundingRect().size().rwidth()){
                //game->game1->sendGhostsToStartPos();
                x->boundingRect().size().rwidth() -= 2;
                for(auto a: game->game1->ghosts){
                    if(a->boundingRect().size().rwidth() == x->boundingRect().size().rwidth() - 3)
                        a->sendToInitial();
                }
                x->boundingRect().size().rwidth() += 2;
                n--;
                game->game1->score->setScore(200*korektivni_faktor);
            }else if(x->boundingRect().size().rwidth()-1 == this->boundingRect().size().rwidth()){
                game->game1->health->decrease();
                if (game->game1->health->getHealth() == 0){
                    this->setDirs0();
                    game->game1->flag = 1;
                    QString message = "You lost :(";
                    game->gameOver(message);
                    std::cout << "VISE SRECE DRUGIT PUT!!!\n";
                    //QCoreApplication::quit();
                    return;
                }
                else {

                    game->game1->sendGhostsToStartPos();
                    setPos(game->game1->pacPosX,game->game1->pacPosY);
                    return;
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
        setPos(this->scene()->width() -2, getY());
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

void Pacman::setNextDirection(int x)
{
    this->nextDirection = x%5;
}

void Pacman::setDirs0()
{
    this->setNextDirection(0);
    this->setCurrentDirection(0);
}

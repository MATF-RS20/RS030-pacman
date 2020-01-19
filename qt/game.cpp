#include "game.h"
#include <QDebug>
#include <iterator>


#include "wall.h"
#include "pacman.h"
#include "ghost.h"
#include "score.h"
#include "health.h"


#include <list>
#include <map>
//#include <QMediaPlayer>
#include "dot.h"
#include <QPixmap>
#include <vector>
#include <algorithm>
#include <QImage>

//#include <cstdlib>
#include <bits/stdc++.h>
//#include "globalVariables.h"

extern int level_map;
//using namespace global;

int screen1width = 800;
int screen1height = 800;

bool myfunction (std::pair<QString*,int> i,std::pair<QString*,int> j) { return (i.second>j.second); }

int Game::getMapX() const
{
    return this->game1->getX();
}
int Game::getMapY() const{
    return this->game1->getY();
}

Game::Game(QWidget *parent)
{
    //QSize size = qApp->screens()[0]->size();

    //this->setFixedSize(size.width(), size.height());
    /*
        PacmanGame g(1);
        this->setFixedSize(g.getX()+200,g.getY()+50);
    */
    //readScores();

    this->setFixedSize(screen1width,screen1height); //(size.width(), size.height())
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    scene = new QGraphicsScene();
    //scene->setSceneRect(0, 0, size.width(), size.height());
    scene->setSceneRect(0, 0, screen1width, screen1height);
    //  Creating an item to place in the scene
    setScene(scene);


}


void Game::displayMainManu()
{
    scene->clear();

    if(!highScoresLoaded){

        QFile inputFile(":/new/PacFiles/score.txt");
        if (inputFile.open(QIODevice::ReadOnly))
        {
           int i = 0;
           QTextStream in(&inputFile);
           QString s;
           int sk;
           while (!in.atEnd() && i < 10)
           {
               in >> s;
               in >> sk;
               highScores[i] = std::pair<QString*,int>(new QString(s),sk);
                  i++;
           }
           std::sort(std::begin(highScores),std::end(highScores),myfunction);
           inputFile.close();
        }
        highScoresLoaded = true;
    }



    //QPixmap m(":/Images/pacmanManu.jpg");
    //QImage l(":/Images/pacmanManu.jpg");
    //scene->addPixmap(m);
    //this->setPixmap(QPixmap(":/Images/pacmanManu.jpg"));
   // scene->setBackgroundBrush(m.scaled(100,100,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    //scene->setBackgroundBrush(QBrush);
    //this->setScene(scene);

    //this->setFixedSize(screen1width,screen1height);
    scene->setSceneRect(0, 0, screen1width, screen1height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    //setBrush(brush);
    scene->setBackgroundBrush(brush);

    //QPixmap m(":/Images/pacmanManu.jpg");

    QGraphicsTextItem *text =  new QGraphicsTextItem(QString("P A C M A N"));
    //text->setScale(100);
    text->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2- text->boundingRect().width()/2;
    //int txPos = screen1width/2- text->boundingRect().width()/2;
    int tyPos = 150;
    text->setPos(txPos,tyPos);
    scene->addItem(text);


    //level_map = 0;


    Button *playButton = new Button(QString("Play"));
    int bxPos = this->width()/2- playButton->boundingRect().width()/2;
    //int bxPos = screen1width/2- playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    QObject::connect(playButton, SIGNAL(clicked()),this, SLOT(start()) );
    this->scene->addItem(playButton);

    Button *scoreButton = new Button(QString("Score"));
    bxPos = this->width()/2- scoreButton->boundingRect().width()/2;
    //bxPos = screen1width/2- scoreButton->boundingRect().width()/2;
    byPos = 350;
    scoreButton->setPos(bxPos,byPos);
    QObject::connect(scoreButton, SIGNAL(clicked()),this, SLOT(score()) );
    this->scene->addItem(scoreButton);


    Button *quitButton = new Button(QString("Quit"));
    bxPos = this->width()/2- quitButton->boundingRect().width()/2;
    //bxPos = screen1width/2- quitButton->boundingRect().width()/2;
    byPos = 425;
    quitButton->setPos(bxPos,byPos);
    QObject::connect(quitButton, SIGNAL(clicked()),this, SLOT(close()) );
    this->scene->addItem(quitButton);

}
/*
int indeks(int rezultat, std::list<std::pair<std::string, int> > & l){


    std::list<std::pair<std::string, int> >::iterator it;
    for (int i =0 ,it=l.begin(); it!=l.end(); it++, i++){
        if (rezultat >= (*it)->second){
            // vector vec sortiran opadajuce
            return i;
        }

    }
    return -1;

}
*/

void Game::gameStop()
{
    for (size_t i=0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }
}

void Game::gameOver(QString message)
{
    /*
    for (size_t i=0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }
    */
    gameStop();
    int sk = this->game1->score->getScore();
    if(sk > highScores[9].second)
    {
        highScores[9] = std::pair<QString*,int>(new QString("Player"), sk);
        sort(std::begin(highScores),std::end(highScores),myfunction);

        // ovaj deo ne radi :(
        QFile outputFile(":/new/PacFiles/score.txt");
        outputFile.open(QIODevice::WriteOnly);
        if (outputFile.isOpen())
        {
            QTextStream outStream(&outputFile);
            for(auto x : highScores)
            {
                outStream << QString(QString(*x.first) + " " + QString::number(x.second) + "\n");
            }
        }
        else
        {
            qDebug() << outputFile.errorString() << "\n";
        }
        outputFile.close();
    }

    qDebug() << "usli smo u funkciju gameOver()";
  //  scene->clear();
    qDebug() << "ocistili smo ekran";


/*


    int i = indeks(this->game1->score->getScore(), listOfScores);
    if( i >= 0){
        // nas score idde u listu
        // da omogucimo korisniku da unese svoje ime

        std::pair<std::string, int> tmp("bla", this->game1->score->getScore());

        //std::vector<std::pair<std::string, int> > tmp;
        //std::copy(listOfScores.begin(), listOfScores.end(), tmp.begin());
        listOfScores.insert(i,tmp);

        // treba da azuriramo nas text fajl
        QFile inputFile(":/new/PacFiles/score.txt");
        if (inputFile.open(QIODevice::ReadWrite)){
                       std::list<std::pair<std::string, int> >::iterator it;
                       for (int i=1, it=listOfScores.begin(); it!=listOfScores.end(); it++, i++){
                        QString player = QString(QString(i)+ ". " + QString(*it->first)+ " " + QString(*it->second));
                                QTextStream stream(&inputFile);
                                stream << player << endl;
                       }
         }
    }// end of if(i>=0)

*/
/*
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    //setBrush(brush);
    scene->setBackgroundBrush(brush);
*/

    QGraphicsTextItem *text1 =  new QGraphicsTextItem(message);
    QFont font;
    font.setPixelSize(60);
    text1->setFont(font);
    //text1->setDefaultTextColor(Qt::white);
    int txPos1 = this->game1->getX()/2 - text1->boundingRect().width()/2;
    int tyPos1 = this->game1->getY()/10;
    text1->setPos(txPos1,tyPos1);
    scene->addItem(text1);

    Button *scoreButton = new Button(QString("Score"));
    int bxPos = this->game1->getX()/2 - scoreButton->boundingRect().width()/2;
    int byPos = 2*this->game1->getY()/7+20;
    scoreButton->setPos(bxPos,byPos);
    QObject::connect(scoreButton, SIGNAL(clicked()),this, SLOT(score()) );
    this->scene->addItem(scoreButton);

    Button *mainButton = new Button(QString("Main Menu"));
    bxPos = this->game1->getX()/2 - mainButton->boundingRect().width()/2;
    byPos = 3*this->game1->getY()/7+20;
    mainButton->setPos(bxPos,byPos);
    QObject::connect(mainButton, SIGNAL(clicked()),this, SLOT(resetGame()) );
    this->scene->addItem(mainButton);



    Button *quitButton = new Button(QString("Quit"));
    bxPos = this->game1->getX()/2 - quitButton->boundingRect().width()/2;
    byPos = 4*this->game1->getY()/7+20;
    quitButton->setPos(bxPos,byPos);
    QObject::connect(quitButton, SIGNAL(clicked()),this, SLOT(close()) );
    this->scene->addItem(quitButton);




}


void Game::score(){
    scene->clear();

    //this->setFixedSize(screen1width,screen1height);
    scene->setSceneRect(0, 0, screen1width, screen1height);
    QGraphicsTextItem *text =  new QGraphicsTextItem(QString("S C O R E"));
    text->setDefaultTextColor(Qt::magenta);
    int txPos = this->width()/2- text->boundingRect().width()/2;
    int tyPos = 150;
    text->setPos(txPos,tyPos);
    scene->addItem(text);

    QString tekst;
    int i = 0;
    for(auto x : highScores){

        tyPos = 200+i*20;

        tekst = QString(*x.first);
        text =  new QGraphicsTextItem(tekst);
        text->setDefaultTextColor(Qt::magenta);
        txPos = this->width()/2- text->boundingRect().width();

        text->setPos(txPos,tyPos);
        scene->addItem(text);

        tekst = QString(" " + QString::number(x.second));
        text =  new QGraphicsTextItem(tekst);
        text->setDefaultTextColor(Qt::magenta);
        txPos = this->width()/2;

        text->setPos(txPos,tyPos);
        scene->addItem(text);
        i++;
    }





    Button *mainButton = new Button(QString("Main Menu"));
    int bxPos = this->width()/2- mainButton->boundingRect().width()/2;
    int byPos = 450;
    mainButton->setPos(bxPos,byPos);
    QObject::connect(mainButton, SIGNAL(clicked()),this, SLOT(resetGame()) );
    this->scene->addItem(mainButton);



    Button *quitButton = new Button(QString("Quit"));
    bxPos = this->width()/2- quitButton->boundingRect().width()/2;
    byPos = 525;
    quitButton->setPos(bxPos,byPos);
    QObject::connect(quitButton, SIGNAL(clicked()),this, SLOT(close()) );
    this->scene->addItem(quitButton);

    scene->update();
}



void Game::again(){
    for (size_t i=0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }

    qDebug() << "usli smo u funkciju again()";
    //scene->clear();




    Button *resetButton = new Button(QString("NEXT LEVEL"));
    int bxPos = this->game1->getX()/2- resetButton->boundingRect().width()/2;
    int byPos = 125;
    resetButton->setPos(bxPos,byPos);
    QObject::connect(resetButton, SIGNAL(clicked()),this, SLOT(start()) );
    this->scene->addItem(resetButton);


    Button *mainButton = new Button(QString("Main Menu"));
    bxPos = this->game1->getX()/2- mainButton->boundingRect().width()/2;
    byPos = 200;
    mainButton->setPos(bxPos,byPos);
    QObject::connect(mainButton, SIGNAL(clicked()),this, SLOT(resetGame()) );
    this->scene->addItem(mainButton);


    Button *quitButton = new Button(QString("Quit"));
    bxPos = this->game1->getX()/2- quitButton->boundingRect().width()/2;
    byPos = 275;
    quitButton->setPos(bxPos,byPos);
    QObject::connect(quitButton, SIGNAL(clicked()),this, SLOT(close()) );
    this->scene->addItem(quitButton);
}







void Game::start()
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    //setBrush(brush);
    scene->setBackgroundBrush(brush);

   // qDebug() << "poziva se reset";
    for (size_t i=0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }

    //Pacman *pucky;
    int scr = 0;
    int hearts = 3;
    if(level_map > 1){
        scr = this->game1->score->getScore();
        hearts = this->game1->health->getHealth();
    }
/*    int i = 0;
    while(true){
    try {
        //pucky = new Pacman(this->game1->getPacman()->getX(), this->game1->getPacman()->getY());
        scr = this->game1->score->getScore();
        hearts = this->game1->health->getHealth();
        goingNextLevel = true;

    } catch (...) {

    }
    }
*/
    qDebug() << "uslo u funkciju start()";

    this->scene->clear();

    //int level_map =1;
    game1 = new PacmanGame(level_map,hearts,scr);


//OVDE brE
    /*this->setFixedSize(game1->getX(),game1->getY());
    scene->setSceneRect(0,0,game1->getX(),game1->getY());*/

    scene->setSceneRect(0,0,game1->getX(),game1->getY());
    qDebug() << this->width()/2-game1->getX()/2 << ", " << this->height()/2-game1->getY()/2 << "\n";

    game1->getPacman()->setFlag(QGraphicsItem::ItemIsFocusable);
    game1->getPacman()->setFocus();
    game1->populateScene(*this->scene);


    //  Adding a view so that we can see something

    this->scene->addItem(game1);
    qDebug() << "level je "<< level_map <<"\n";
    //scene->addItem(game1->getPacman());

}

void Game::resetGame()
{
    qDebug() << "poziva se reset";
    for (size_t i=0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }
    level_map =1;
    scene->clear();
    this->displayMainManu();
    //start();
}

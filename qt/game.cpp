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


    scene->setSceneRect(0, 0, screen1width, screen1height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    //setBrush(brush);
    scene->setBackgroundBrush(brush);


    QGraphicsTextItem *text =  new QGraphicsTextItem(QString("P A C M A N"));
    //text->setScale(100);
    text->setDefaultTextColor(Qt::white);
    int txPos = this->width()/2- text->boundingRect().width()/2;
    int tyPos = 150;
    text->setPos(txPos,tyPos);
    scene->addItem(text);


    //level_map = 0;


    Button *playButton = new Button(QString("Play"),200,50);
    int bxPos = this->width()/2- playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    QObject::connect(playButton, SIGNAL(clicked()),this, SLOT(start()) );
    this->scene->addItem(playButton);

    Button *scoreButton = new Button(QString("Score"), 200, 50);
    bxPos = this->width()/2- scoreButton->boundingRect().width()/2;
    //bxPos = screen1width/2- scoreButton->boundingRect().width()/2;
    byPos = 350;
    scoreButton->setPos(bxPos,byPos);
    QObject::connect(scoreButton, SIGNAL(clicked()),this, SLOT(score()) );
    this->scene->addItem(scoreButton);


    Button *quitButton = new Button(QString("Quit"), 200, 50);
    bxPos = this->width()/2- quitButton->boundingRect().width()/2;
    //bxPos = screen1width/2- quitButton->boundingRect().width()/2;
    byPos = 425;
    quitButton->setPos(bxPos,byPos);
    QObject::connect(quitButton, SIGNAL(clicked()),this, SLOT(close()) );
    this->scene->addItem(quitButton);

}


void Game::gameStop()
{
    for (size_t i=0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }
}


/*
void Game::tastatura(QGraphicsScene *highScene)
{
    std::vector<QString> abeceda ={"A","B","C","D","E","F","G",
                                   "H","I","J","K","L","M","N",
                                   "O","P","Q","R","S","T","U",
                                   "V","W","X","Y","Z", "DONE"
                                  };
    int spacing =70;
    int bx = 40;
    int by = 200;
    int i =0;
    for (auto x: abeceda){
        Button *dugme = new Button(x,50,50);
        bx = bx +  spacing;
        if(i == 7){
            by = by + spacing;
            i =0;
            bx = 110;
        }

        dugme->setPos(bx,by);
        if (x == "DONE"){
            QObject::connect(dugme, SIGNAL(clicked()),this, SLOT(changeScene()) );
        }else{
            auto f = [x,this](){writeName(x);};
            QObject::connect(dugme, SIGNAL(clicked()),this, SLOT(f()) );
            //writeName(x);
        }
        highScene->addItem(dugme);
        ++i;
    }//end of for

}


void Game::writeName(QString x){

    playersName += x;
    QString *name = new QString(playersName);
    QGraphicsTextItem *nameBar =  new QGraphicsTextItem(*name);
    QFont font;
    font.setPixelSize(30);
    nameBar->setFont(font);
    //text1->setDefaultTextColor(Qt::white);
    int xPos1 = this->game1->getX()/2 - nameBar->boundingRect().width()/2;
    int yPos1 = this->game1->getY()/10 + 50;
    nameBar->setPos(xPos1,yPos1);

    this->highScene->addItem(nameBar);
    this->highScene->update();

    qDebug()<< playersName;
}

void Game::changeScene(){
    qDebug() << "================";
    QString *name = new QString(playersName);
    qDebug() << *name;
    player = *name;
    playersName = "";

    setScene(scene);
    show();
}
*/


void Game::gameOver(QString message)
{

    gameStop();

    int sk = this->game1->score->getScore();
    if(sk > highScores[9].second)
    {
        /*
        //=========AJ DA VIDIMO I TAJ HIGHSCORE DA SE UNOSI=======//
        this->hide();

        highScene = new QGraphicsScene();
        highScene->setSceneRect(0, 0, screen1width, screen1height);
        //  Creating an item to place in the scene
        setScene(highScene);
        show();


        QGraphicsTextItem *nameBar =  new QGraphicsTextItem("Type your name");
        QFont font;
        font.setPixelSize(60);
        nameBar->setFont(font);
        //text1->setDefaultTextColor(Qt::white);
        int xPos1 = this->game1->getX()/2 - nameBar->boundingRect().width()/2;
        int yPos1 = this->game1->getY()/10;
        nameBar->setPos(xPos1,yPos1);
        highScene->addItem(nameBar);

        tastatura(highScene);


        // kada upisemo userName onda se vracamo na staru scenu
        //setScene(scene);

         */
        highScores[9] = std::pair<QString*,int>(new QString(player), sk);
        QString *whichPlayer = new QString(&player + QString::number(howManyGames));
        howManyGames++;
        highScores[9] = std::pair<QString*,int>(whichPlayer, sk);
        sort(std::begin(highScores),std::end(highScores),myfunction);

        // ---===---   ---===---   ---===---
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
    //else{//         <- UKLJUCITI KAD SE ODRADI HIGHSCORE

    qDebug() << "usli smo u funkciju gameOver()";
  //  scene->clear();
    qDebug() << "ocistili smo ekran";



    QGraphicsTextItem *text1 =  new QGraphicsTextItem(message);
    QFont font;
    font.setPixelSize(60);
    text1->setFont(font);
    //text1->setDefaultTextColor(Qt::white);
    int txPos1 = this->game1->getX()/2 - text1->boundingRect().width()/2;
    int tyPos1 = this->game1->getY()/10;
    text1->setPos(txPos1,tyPos1);
    scene->addItem(text1);

    Button *scoreButton = new Button(QString("Score"), 200, 50);
    int bxPos = this->game1->getX()/2 - scoreButton->boundingRect().width()/2;
    int byPos = 2*this->game1->getY()/7+20;
    scoreButton->setPos(bxPos,byPos);
    QObject::connect(scoreButton, SIGNAL(clicked()),this, SLOT(score()) );
    this->scene->addItem(scoreButton);

    Button *mainButton = new Button(QString("Main Menu"), 200, 50);
    bxPos = this->game1->getX()/2 - mainButton->boundingRect().width()/2;
    byPos = 3*this->game1->getY()/7+20;
    mainButton->setPos(bxPos,byPos);
    QObject::connect(mainButton, SIGNAL(clicked()),this, SLOT(resetGame()) );
    this->scene->addItem(mainButton);



    Button *quitButton = new Button(QString("Quit"), 200, 50);
    bxPos = this->game1->getX()/2 - quitButton->boundingRect().width()/2;
    byPos = 4*this->game1->getY()/7+20;
    quitButton->setPos(bxPos,byPos);
    QObject::connect(quitButton, SIGNAL(clicked()),this, SLOT(close()) );
    this->scene->addItem(quitButton);


//}//           <- OD ELSE-A za HIGHSCORE

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





    Button *mainButton = new Button(QString("Main Menu"), 200, 50);
    int bxPos = this->width()/2- mainButton->boundingRect().width()/2;
    int byPos = 450;
    mainButton->setPos(bxPos,byPos);
    QObject::connect(mainButton, SIGNAL(clicked()),this, SLOT(resetGame()) );
    this->scene->addItem(mainButton);



    Button *quitButton = new Button(QString("Quit"), 200, 50);
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




    Button *resetButton = new Button(QString("NEXT LEVEL"), 200, 50);
    int bxPos = this->game1->getX()/2- resetButton->boundingRect().width()/2;
    int byPos = 125;
    resetButton->setPos(bxPos,byPos);
    QObject::connect(resetButton, SIGNAL(clicked()),this, SLOT(start()) );
    this->scene->addItem(resetButton);


    Button *mainButton = new Button(QString("Main Menu"), 200, 50);
    bxPos = this->game1->getX()/2- mainButton->boundingRect().width()/2;
    byPos = 200;
    mainButton->setPos(bxPos,byPos);
    QObject::connect(mainButton, SIGNAL(clicked()),this, SLOT(resetGame()) );
    this->scene->addItem(mainButton);


    Button *quitButton = new Button(QString("Quit"), 200, 50);
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


    int scr = 0;
    int hearts = 3;
    if(level_map > 1){
        scr = this->game1->score->getScore();
        hearts = this->game1->health->getHealth();
    }


    this->scene->clear();


    game1 = new PacmanGame(level_map,hearts,scr);


    scene->setSceneRect(0,0,game1->getX(),game1->getY());
    qDebug() << this->width()/2-game1->getX()/2 << ", " << this->height()/2-game1->getY()/2 << "\n";

    game1->getPacman()->setFlag(QGraphicsItem::ItemIsFocusable);
    game1->getPacman()->setFocus();
    game1->populateScene(*this->scene);


    //  Adding a view so that we can see something

    this->scene->addItem(game1);
    qDebug() << "level je "<< level_map <<"\n";


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

}

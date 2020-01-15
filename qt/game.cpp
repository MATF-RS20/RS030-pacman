#include "game.h"
#include <QDebug>

Game::Game(QWidget *parent)
{
    QSize size = qApp->screens()[0]->size();

    this->setFixedSize(size.width(), size.height());
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, size.width(), size.height());
    //  Creating an item to place in the scene
    setScene(scene);


}

void Game::displayMainManu()
{
    //this->setPixmap(QPixmap(":/Images/pacmanManu.jpg"));

    QGraphicsTextItem *text =  new QGraphicsTextItem(QString("P A C M A N"));
    int txPos = this->width()/2- text->boundingRect().width()/2;
    int tyPos = 150;
    text->setPos(txPos,tyPos);
    scene->addItem(text);


    int level_map = 1;

    Button *playButton = new Button(QString("Play"));
    int bxPos = this->width()/2- playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    QObject::connect(playButton, SIGNAL(clicked()),this, SLOT(start( level_map )) );
    this->scene->addItem(playButton);


    Button *quitButton = new Button(QString("Quit"));
    bxPos = this->width()/2- quitButton->boundingRect().width()/2;
    byPos = 350;
    quitButton->setPos(bxPos,byPos);
    QObject::connect(quitButton, SIGNAL(clicked()),this, SLOT(close()) );
    this->scene->addItem(quitButton);

}

void Game::gameOver(QString message)
{
    for (size_t i=0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }


    //scene->removeItem(game1);
    //delete game1;
    qDebug() << "usli smo u funkciju gameOver()";
    //scene->clear();
    qDebug() << "ocistili smo ekran";


    QGraphicsTextItem *text1 =  new QGraphicsTextItem(message);
    //QFont font;
    //font.setPixelSize(60);
    //text->setFont(font);
    int txPos1 = this->width()/2- text1->boundingRect().width()/2;
    int tyPos1 = 150;
    text1->setPos(txPos1,tyPos1);
    scene->addItem(text1);

    Button *resetButton = new Button(QString("Play again"));
    int bxPos = this->width()/2- resetButton->boundingRect().width()/2;
    int byPos = 125;
    resetButton->setPos(bxPos,byPos);
    QObject::connect(resetButton, SIGNAL(clicked()),this, SLOT(resetGame()) );
    this->scene->addItem(resetButton);



    Button *quitButton = new Button(QString("Quit"));
    bxPos = this->width()/2- quitButton->boundingRect().width()/2;
    byPos = 350;
    quitButton->setPos(bxPos,byPos);
    QObject::connect(quitButton, SIGNAL(clicked()),this, SLOT(close()) );
    this->scene->addItem(quitButton);



    //scene->update();
   // scene->clear();
    //this->displayMainManu();

}



void Game::start(int level_map)
{
    this->scene->clear();

    //int level_map =1;
    game1 = new PacmanGame(level_map);

    game1->getPacman()->setFlag(QGraphicsItem::ItemIsFocusable);
    game1->getPacman()->setFocus();
    game1->populateScene(*this->scene);

    //  Adding a view so that we can see something

    this->scene->addItem(game1);
    //scene->addItem(game1->getPacman());

}

void Game::resetGame()
{
    //delete game1->pacman;
    //for (size_t i =0 ; i<4; i++){
    //game1->ghosts.clear();
    //}
    //game1->walls_and_borders.clear();
    //game1->dots.clear();
    int level_map =1;
    scene->clear();
    start(level_map);
}

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

#include <QScreen>
#include "wall.h"
#include "pacmangame.h"


//#include "pacman.h"
//#include "ghost.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //  Creating a scene
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);

    QSize size = qApp->screens()[0]->size();

    view->setFixedSize(size.width(), size.height());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0, 0, size.width(), size.height());
    //  Creating an item to place in the scene


    PacmanGame *game1 = new PacmanGame(); //prave se zidovi, pacman i duhovi
    scene->addItem(game1);
    scene->addItem(game1->getPacman());

    game1->getPacman()->setFlag(QGraphicsItem::ItemIsFocusable);
    game1->getPacman()->setFocus();

    //Character *box = new Character(0, 0, 20, 35, 1000, 1000);
    Wall *w1 = new Wall(50, 400, 10, 200);
    Wall *w2 = new Wall(50, 410, 100, 10);
    Wall *w3 = new Wall(360, 470, 40, 10);
    Wall *w4 = new Wall(50, 520, 10,300);





    game1->populateScene(*scene);

    //  Adding a view so that we can see something




    // And show it
     view->showFullScreen();


//----------------------------------------------------
/*
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    Pacman *pacman = new Pacman();
    scene->addItem(pacman);

    pacman->setFlag(QGraphicsItem::ItemIsFocusable);
    pacman->setFocus();

    Ghost *ghost = new Ghost ();
    scene->addItem(ghost);

    QGraphicsView * view = new QGraphicsView(scene);
    view->show();

    view->setFixedSize(800,600);



    QGraphicsRectItem * rect = new QGraphicsRectItem();
    rect->setRect(150,150,30,30);
    scene->addItem(rect);

*/
    return a.exec();
}



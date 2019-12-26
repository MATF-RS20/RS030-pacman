#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScreen>
#include <QDebug>
//#include "Character.h"
#include "wall.h"
#include "pacmangame.h"


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


    PacmanGame *game1 = new PacmanGame();

    //Character *box = new Character(0, 0, 20, 35, 1000, 1000);
    // Wall *w1 = new Wall(50, 400, 10, 200);
    // Wall *w2 = new Wall(50, 410, 100, 10);
    // Wall *w3 = new Wall(360, 470, 40, 10);
    // Wall *w4 = new Wall(50, 520, 10,300);


    game1->getPacman()->setFlag(QGraphicsItem::ItemIsFocusable);
    game1->getPacman()->setFocus();
    //box->setFlag(QGraphicsItem::ItemIsFocusable);
    //box->setFocus();

    // Upper left corner    position x, y, then width and height

    //  Adding the item to the scene
    //scene->addItem(box);
    game1->populateScene(*scene);

    //  Adding a view so that we can see something
    scene->addItem(game1);
    //scene->addItem(game1->getPacman());



    // And show it

    //box->setPos(0, 0);
    view->showFullScreen();


    return a.exec();
}

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScreen>
#include <QDebug>
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

    game1->getPacman()->setFlag(QGraphicsItem::ItemIsFocusable);
    game1->getPacman()->setFocus();

    // Upper left corner    position x, y, then width and height

    game1->populateScene(*scene);

    //  Adding a view so that we can see something
    scene->addItem(game1);
    //scene->addItem(game1->getPacman());



    // And show it

    view->showFullScreen();



    return a.exec();
}

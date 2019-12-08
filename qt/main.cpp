#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScreen>
#include <MyRect.h>



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
    MyRect *rect = new MyRect(0, 0, 20, 20, size);

    // Upper left corner    position x, y, then width and height
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //  Adding the item to the scene
    scene->addItem(rect);

    //  Adding a view so that we can see something




    // And show it


    rect->setPos(0, 0);
    view->showFullScreen();


    return a.exec();
}

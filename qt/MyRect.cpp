#include "MyRect.h"


MyRect::MyRect(int x1, int y1, int x2, int y2, QSize size1)
{
    setRect(x1, y1, x2, y2);
    size = size1;
    width = x2;
    height = y2;
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(25);


}

void MyRect::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        x1 = -5;
        y1 = 0;
    }else if(event->key() == Qt::Key_Right){
        x1 = 5;
        y1 = 0;
    }else if(event->key() == Qt::Key_Up){
        x1 = 0;
        y1 = -5;
    }else if(event->key() == Qt::Key_Down){
        x1 = 0;
        y1 = 5;
    }else if(event->key() == Qt::Key_Escape){
        QCoreApplication::quit();
    }

}

void MyRect::move()
{
    setPos(x() + x1, y() + y1);

    if(x() < 0)
        setPos(0, y());
    if(y() < 0)
        setPos(x(), 0);
    if(x() > size.width() - this->width)
        setPos(size.width()  - this->width, y());
    if(y() > size.height() - this->height)
        setPos(x(), size.height() - this->height);
}



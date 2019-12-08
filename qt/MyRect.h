#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QCoreApplication>
#include <QSize>

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    MyRect(int x1, int y1, int x2, int y2, QSize size1);
    void keyPressEvent(QKeyEvent *event);
public slots:
    void move();
private:
    int x1 = 0;//speed
    int y1 = 0;
    int width;
    int height;
    QSize size;
};



#endif // MYRECT_H

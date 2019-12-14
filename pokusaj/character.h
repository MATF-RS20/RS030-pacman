#ifndef CHARACTER_H
#define CHARACTER_H

//#include <QGraphicsRectItem>
//#include <QObject>


#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QTimer>
#include <QObject>
#include <QCoreApplication>
#include <QSize>


typedef struct position {
    int x;
    int y;
}Position;


class Character: public QGraphicsRectItem{
   // Q_OBJECT
public:
    Character(int x, int y, int width, int height);

    int getWidth();
    int getHeight();
    int getX();
    int getY();

//public slots:
  //  virtual void move();
private:
    int x;
    int y;
    int width;
    int height;

    QSize size;
};




//----------------------------------------------
/*
class Character: public QGraphicsRectItem{
   // Q_OBJECT
public:
    Character () = default;
    Character(int x1, int y1, int width1, int height1);
    int getHeight();
    int getWidth();
    int getX();
    int getY();

//public slots:
  //  virtual void move();
protected:
    int x;
    int y;
    int width;
    int height;
}; //end of class Character
*/


#endif // CHARACTER_H

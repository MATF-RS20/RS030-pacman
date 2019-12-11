#ifndef CHARACTER_H
#define CHARACTER_H



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


class Character: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Character(int x, int y, int width, int height , int sizeX, int sizeY);

    bool isAvailable(int where);
    void setCurrentDirection(int where);
    void setNextDirection(int where);
    void setAvailable(int i, bool yesNo);
    int getWidth();
    int getHeight();
    bool* getAvailableDirections();
    int getNextDirection();
    int getCurrentDirection();
public slots:
    virtual void move();
private:
    //  speed can be -5, 0 or 5
    //  only one of them should be a non zero value at the same time
    int vertical_step;
    int horizontal_step;
    int width;
    int height;
    int sizeX;
    int sizeY;
    int currentDirection;
    int nextDirection;//1 - left; 2 - right; 3 - up; 4 - down; 0 - none
    bool availableDirections[4];

    QSize size;
};





#endif // CHARACTER_H

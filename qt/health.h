#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem{
public:
    Health(int hearts = 3);
    void decrease();
    void setHealth(int x);
    int getHealth();
private:
    int health;

};

#endif // HEALTH_H

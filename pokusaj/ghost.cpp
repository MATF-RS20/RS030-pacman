#include "ghost.h"
#include <QTimer>


//Ghost::Ghost(int x1, int y1, int width1, int height1)
    //:Character(x1,y1,width1,height1)
  //  :x(x1), y(y1), width(width1), height(height1)

Ghost::Ghost()
{
    setRect(0,0,50,50);  //x i y ce zavisiti od mape ali ovako za sada
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(move()));
    timer->start(25);

}

void Ghost::move(){
    // ideja
    // 4 duha 4 razlicita kretanja i kretanje da zavisi od id-ja koji ce dobiti svaki duh i koji je unikatan
    // za sada ovako
    // plus treba dodati ako udari o zid menja pravac


        setPos(this->x(), this->y()-20);

}

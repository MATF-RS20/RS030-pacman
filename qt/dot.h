#ifndef DOT_HPP
#define DOT_HPP
#include <QGraphicsEllipseItem>
#include <QRectF>

class Dot{
public:
    Dot();
    Dot(int x, int y , char r = '0');
    void destroy();
    QRectF getDot();
private:
    int posX;
    int posY;
    /*
    int diameter;
    */
    QRectF *bobby;
    int points;
    bool turnsGhostsBlue;
};

#endif // DOT_HPP

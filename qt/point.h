#ifndef POINT_H
#define POINT_H

class Point{
public:

    Point ();
    Point (int _x, int _y);

    int length();

    int getX();
    int getY();
    void setX(int x1);
    void setY(int y1);


    Point operator-(Point p1);

    int x;
    int y;

};



#endif // POINT_H

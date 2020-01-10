#include "dot.h"

Dot::Dot(int x, int y , char r){
    posX = x;
    posY = y;
    if(r == '0'){
        points = 20;
        turnsGhostsBlue = false;
        bobby = new QRectF(x+15, y+15, 4, 4);
    }
    else if(r == 'B'){
        points = 0;
        turnsGhostsBlue = true;
        bobby = new QRectF(x+12, y+12, 10, 10);
    }
    else if(r == 'V'){
        points = 200;
        turnsGhostsBlue = true;
        bobby = new QRectF(x+9, y+9, 19, 19);
    }
}

Dot::Dot(){
    bobby = nullptr;
}

QRectF Dot::getDot(){
    return *bobby;
}

int Dot::getPoints(){
    return points;
}

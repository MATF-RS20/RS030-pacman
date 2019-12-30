#include "dot.h"

Dot::Dot(int x, int y , char r){
    posX = x;
    posY = y;
    if(r == '0'){
        points = 20;
        turnsGhostsBlue = false;
        bobby = new QRectF(x+15, y+15, 4, 4);
    }
    else{
        points = 0;
        turnsGhostsBlue = true;
        bobby = new QRectF(x+12, y+12, 10, 10);
    }
}

Dot::Dot(){
    bobby = nullptr;
}

void Dot::destroy(){
    delete bobby;
}

QRectF Dot::getDot(){
    return *bobby;
}

#ifndef NODE_H
#define NODE_H


#include <cfloat>

class Node {
public:
    int x;
    int y;
    bool isNotWall;
    int parentX;
    int parentY;
    float gCost;
    float hCost;
    float fCost;



    Node()
        : x(), y()//, isNotWall(true)
    {
        isNotWall = true;
        parentX = -1;
        parentY = -1;
        gCost = FLT_MAX;
        hCost = FLT_MAX;
        fCost = FLT_MAX;
    }


    Node(int x1, int y1, bool isNotWall1)
        :x(x1), y(y1), isNotWall(isNotWall1),parentX(-1), parentY(-1), gCost(FLT_MAX), hCost(FLT_MAX), fCost(FLT_MAX)
    {}

    float getF(){
        return this->gCost + this->hCost;
    }

    void setX(int x1){
        this->x=x1;
    }
    void setY(int y1){
        this->y=y1;
    }

    void setFCost(float fCost1){
        this->fCost = fCost1;
    }


};

inline bool operator < (const Node &l, const Node &r){
    return l.fCost < r.fCost;
}







#endif // NODE_H

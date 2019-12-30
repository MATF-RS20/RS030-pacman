#include "searchcell.h"



SearchCell::SearchCell()
    :parent(0)
{}

SearchCell::SearchCell (int x, int y, SearchCell *_parent)
    :m_xcoord(x), m_ycoord(y), parent(_parent), m_id(y*WORLD_SIZE + y), G(0), H(0)
{}

float SearchCell::getF(){
    return this->G + this->H;
}


float SearchCell::ManHattanDistance (SearchCell *nodeEnd){
    // |x1 - x2| + |y1 - y2|
    return  (float) fabs(this->m_xcoord - nodeEnd->m_xcoord) + (float) fabs(this->m_ycoord - nodeEnd->m_ycoord);
}


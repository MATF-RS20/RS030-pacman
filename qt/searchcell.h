#ifndef SEARCHCELL_H
#define SEARCHCELL_H

#include <math.h>
// #define  WORLD_SIZE 64

class SearchCell {
public:
    int m_xcoord, m_ycoord;
    int m_id;
    SearchCell* parent;
    float G;
    float H;

    SearchCell();
    SearchCell (int x, int y, SearchCell *_parent);

    float getF();
    float ManHattanDistance (SearchCell *nodeEnd);
};


#endif // SEARCHCELL_H

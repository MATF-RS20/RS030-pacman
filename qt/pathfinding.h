#ifndef PATHFINDING_H
#define PATHFINDING_H

//#include "Vector.h"
#include "searchcell.h"
#include <vector>

class PathFinding {
public:
    PathFinding(void);
    ~PathFinding(void);

    void findPath (Vector currentPos, Vector targetPos );
    Vector nextPathPos();

    void clearOpenList();
    void clearVisitedList();
    void clearPathToGoal();

    bool m_initializedStartGoal;
    bool m_foundGoal;

private:
    void setStartAndGoal (SearchCell start, SearchCell goal);
    void pathOpen (int x, int y, float newCost, SearchCell *parent);
    SearchCell *getNextCell();
    void continuePath();
    SearchCell *m_startCell;
    SearchCell *m_goalCell;
    std::vector <SearchCell*> m_openList;
    std::vector <SearchCell*> m_visitedList;
    std::vector <Vector*> m_pathToGoal;


};



#endif // PATHFINDING_H

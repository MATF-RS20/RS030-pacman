#include "pathfinding.h"

PathFinding::PathFinding (void){
    m_initializedStartGoal = false;
    m_foundGoal = false;
}

PathFinding::~PathFinding (void){

}




void PathFinding::findPath(Point currentPos, Point targetPos){
    if (!m_initializedStartGoal){

        for (int i = 0 ; i < m_openList.size(); i++){
            delete m_openList[i];
        }
        m_openList.clear();


        for (int i = 0 ; i < m_visitedList.size(); i++){
            delete m_visitedList[i];
        }
        m_visitedList.clear();


        for (int i = 0 ; i < m_pathToGoal.size(); i++){
            delete m_pathToGoal[i];
        }

        m_pathToGoal.clear();


     //-----------------------------------
    //initialize start
    SearchCell start;
    start.m_xcoord = currentPos.x;
    start.m_ycoord = currentPos.y;

    //initialize goal
    SearchCell goal;
    goal.m_xcoord = targetPos.x;
    goal.m_ycoord = targetPos.y;

    setStartAndGoal(start,goal);
    m_initializedStartGoal = true;

    }// end of if

    if (m_initializedStartGoal){
        continuePath();
    }
}



void PathFinding::clearOpenList(){
    this->m_openList.clear();
}

void PathFinding::clearVisitedList(){
    this->m_visitedList.clear();
}

void PathFinding::clearPathToGoal(){
    this->m_pathToGoal.clear();
}




Point PathFinding::nextPathPos(){

    int indeks = 1;

    Vektor nextPos;
    nextPos.x = m_pathToGoal[m_pathToGoal.size() - indeks].x;
    nextPos.y = m_pathToGoal[m_pathToGoal.size() - indeks].y;

    Point distance =  nextPos - pos;

    if ( indeks < m_pathToGoal.size()){

        if ( distance.length() < radius){

            m_pathToGoal.erase(m_pathToGoal.end() - indeks);
        }

    }// end of first if


    return nextPos;
}






//private:
void PathFinding::setStartAndGoal (SearchCell start, SearchCell goal){

    m_startCell = new SearchCell (start.m_xcoord, start.m_ycoord, NULL);
    m_goalCell = new SearchCell (goal.m_xcoord, goal.m_ycoord, &goal);


    m_startCell->G = 0;  // G cost je udaljenost od starta
    m_startCell->H = m_startCell->ManHattanDistance(m_goalCell);
    m_startCell->parent = 0;

    m_openList.push_back(m_startCell);
}






void PathFinding::pathOpen (int x, int y, float newCost, SearchCell *parent){

    /*
    if (CELL_BLOCKED){
        return;
    }
    */

    int id = y*WORLD_SIZE + x;

    for (int i = 0 ; i < m_visitedList.size(); i++){

        if (id == m_visitedList[i]->m_id){
            return;
        }
    }

    SearchCell *newChild = new SearchCell(x,y,parent);
    newChild->G = newCost;
    newChild->H = parent->ManHattanDistance(m_goalCell);


    for (int i = 0 ; i < m_openList.size(); i++){

        if (id == m_openList[i]->m_id){

            float newF = newChild->G + newCost + m_openList[i]->H;

            if (m_openList[i]->getF() > newF){

                m_openList[i]->G = newChild->G + newCost;
                m_openList[i]->parent = newChild;
            } else {
                delete newChild;
                return;
            }
        }

    }// end of for

    m_openList.push_back(newChild);
}








// put koji je za nas najbolji je onaj u kome celije imaju najmanje F
// moze se desiti da vise celija imaju istu vr F-a., tada gledamo najmanje H
// ovde trazimo takvo F = G + H
// G udaljenost celije od starta
// H udaljenost celije od enda i racunamo preko Manhattan rastojanja
SearchCell* PathFinding::getNextCell(){

    float bestF = 999999.0f;
    int cellIndex = -1;
    SearchCell* nextCell = NULL;

    for (int i = 0; i < m_openList.size(); i++){

        if (m_openList[i]->getF() < bestF){
            bestF = m_openList[i]->getF();
            cellIndex = i;
        }
    }

    if (cellIndex >= 0){
        nextCell = m_openList[cellIndex];
        m_visitedList.push_back(nextCell);
        m_openList.erase(m_openList.begin() + cellIndex);
    }

    return nextCell;
}





void PathFinding::continuePath(){

    if (m_openList.empty()){
        return;
    }

    SearchCell* currentCell = this->getNextCell();

    if (currentCell->m_id == m_goalCell->m_id){

        m_goalCell->parent = currentCell->parent;

        SearchCell* getPath;

        for (getPath = m_goalCell; getPath != NULL; getPath = getPath->parent){

            m_pathToGoal.push_back(new Vektor(getPath->m_xcoord, getPath->m_ycoord));
        }


        m_foundGoal = true;
        return;

    } else {

            // right side
            this->pathOpen(currentCell->m_xcoord + 1, currentCell->m_ycoord, currentCell->G + 1, currentCell);


            //left side
            this->pathOpen(currentCell->m_xcoord - 1, currentCell->m_ycoord, currentCell->G + 1, currentCell);

            // up
            this->pathOpen(currentCell->m_xcoord , currentCell->m_ycoord + 1, currentCell->G + 1, currentCell);

            // down
            this->pathOpen(currentCell->m_xcoord , currentCell->m_ycoord - 1, currentCell->G + 1, currentCell);

            // left-up diagonale
            this->pathOpen(currentCell->m_xcoord - 1, currentCell->m_ycoord + 1, currentCell->G + 1.414f, currentCell);

            // right-up diagonale
            this->pathOpen(currentCell->m_xcoord + 1, currentCell->m_ycoord + 1, currentCell->G + 1.414f, currentCell);

            // left-bottom diagonale
            this->pathOpen(currentCell->m_xcoord - 1, currentCell->m_ycoord - 1, currentCell->G + 1.414f, currentCell);

            // right-bottom diagonale
            this->pathOpen(currentCell->m_xcoord + 1, currentCell->m_ycoord - 1, currentCell->G + 1.414f, currentCell);


        for (int i = 0; i < m_openList.size(); i++){

            if (currentCell->m_id == m_openList[i]->m_id){

                m_openList.erase(m_openList.begin() + i);
            }
        }// end of for


    }// end od if-else


}

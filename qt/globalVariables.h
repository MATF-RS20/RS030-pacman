#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include <set>
#include <QGraphicsItem>

/*namespace global{

std::set<QGraphicsItem*> allDots{};           // cuvamo kao skupove ovog tipa jer mozemo da dobijemo
//std::set<QGraphicsRectItem*> allGhosts{};     // pokazivace na objekte u trenutku kad ih ubacujemo na scenu

};
*/

class Global{
public:
    Global(){
        allDots = std::set<QGraphicsItem*>{};
    }
    void addDot(QGraphicsItem* x){
        allDots.insert(x);
    }
    bool allDotsEmpty(){
        return allDots.empty();
    }
    bool allDotsExists(QGraphicsItem* x){
        if(allDots.count(x) == 0)
            return false;
        else return  true;
    }
private:
    static std::set<QGraphicsItem*> allDots;
};
#endif // GLOBALVARIABLES_H

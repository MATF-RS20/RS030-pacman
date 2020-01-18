#ifndef GLOBALVARIABLES_H
#define GLOBALVARIABLES_H

#include <set>
#include <QGraphicsItem>
#include <QString>
#include <QFile>
#include <QTextStream>

namespace global{

//std::set<QGraphicsItem*> allDots{};           // cuvamo kao skupove ovog tipa jer mozemo da dobijemo
//std::set<QGraphicsRectItem*> allGhosts{};     // pokazivace na objekte u trenutku kad ih ubacujemo na scenu

int spacing = 35;
int screen1width = 500;
int screen1height = 600;

QChar nula('0');                // 0 => bobica
QChar kec('1');                 // 1 => zid
QChar taraba('#');              // # => duh
QChar pacPosition('P');         // P => pocetna pozicija
QChar bigDot('B');              // B => velika bobica
QChar fruit('V');              // V => vockica
QChar emptySpace('=');          // '=' => prazan prostor
QChar noviRed('\n');


}

/*
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
*/
#endif // GLOBALVARIABLES_H

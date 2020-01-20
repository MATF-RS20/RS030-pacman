#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScreen>
#include <QDebug>


#include "wall.h"
#include "pacmangame.h"
//#include "globalVariables.h"
#include <iostream>
#include "game.h"
#include <QFile>
#include <QTextStream>
#include <algorithm>
#include <string>
//using namespace global;


Game * game;
int level_map;
//std::list<std::pair<std::string, int> > listOfScores;
//QString playersName = "";
QString player = "Player";



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    level_map = 1;
    game = new Game();

    game->show();
    game->displayMainManu();


    return a.exec();
}

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QScreen>
#include <QDebug>

//#include "Character.h"
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

//PacmanGame *game1;
Game * game;
int level_map;
std::list<std::pair<std::string, int> > listOfScores;



std::pair<std::string, int> split(const std::string & str)
{
    std::vector<std::string> result;

    auto word_begin = str.cbegin();

    // Idemo dok ne stignemo do kraja stringa
    while (word_begin != str.cend())
    {
        // Preskacemo razmake sa pocetka
        word_begin = std::find_if_not(word_begin, str.cend(), isspace);

        // Trazimo kraj reci
        const auto word_end = std::find_if(word_begin, str.cend(), isspace);

        // Kopiramo karaktere u izlazni vektor
        if (word_begin != str.cend())
        {
            result.emplace_back(word_begin, word_end);
        }

        // Zavrsavamo petlju nastavljajuci od kraja prethodne reci
        word_begin = word_end;
    }
    std::pair<std::string, int> tmp(result[0], stoi(result[1]));

    return tmp;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile inputFile(":/new/PacFiles/score.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
       int i = 0;
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString tekst = in.readLine(); // ime i poeni

          std::pair<std::string, int> tmp = split (tekst.toStdString());
          listOfScores.push_back(tmp);
          i++;
       }
       inputFile.close();
    }



    level_map = 1;
    game = new Game();

    game->show();
    game->displayMainManu();


    /*

    //  Creating a scene
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);

    //scene->setBackgroundBrush(QBrush(QImage(":/Puck/bg.jpg")));

    //QSize size = qApp->screens()[0]->size();

    int mapNumber = 4;
    //std::cin >> k;
    game1 = new PacmanGame(mapNumber);

    int mapWidth = game1->getX();
    int mapHeight = game1->getY();
    //std::cout << mapWidth << std::endl;

    view->setFixedSize(mapWidth, mapHeight);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(0, 0, mapWidth, mapHeight);
    //  Creating an item to place in the scene



    //Character *box = new Character(0, 0, 20, 35, 1000, 1000);
    // Wall *w1 = new Wall(50, 400, 10, 200);
    // Wall *w2 = new Wall(50, 410, 100, 10);
    // Wall *w3 = new Wall(360, 470, 40, 10);
    // Wall *w4 = new Wall(50, 520, 10,300);


    game1->getPacman()->setFlag(QGraphicsItem::ItemIsFocusable);
    game1->getPacman()->setFocus();
    //box->setFlag(QGraphicsItem::ItemIsFocusable);
    //box->setFocus();

    // Upper left corner    position x, y, then width and height

    //  Adding the item to the scene
    //scene->addItem(box);
    game1->populateScene(*scene);

    //  Adding a view so that we can see something
    scene->addItem(game1);
    //scene->addItem(game1->getPacman());



    // And show it

    //box->setPos(0, 0);
    view->show();
    //view->showFullScreen();

*/
    return a.exec();
}

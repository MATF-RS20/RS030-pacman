#include "pacmangame.h"

#include <iostream>
#include <QDesktopWidget>
#include <QApplication>

#include <QGraphicsItem>
#include <fstream>
#include <QFile>
#include <stdio.h>
#include <QTextStream>
#include <QChar>
#include <list>
#include <numeric>
#include <QString>
#include "dot.h"
#include <QStyleOption>


#include <exception>


PacmanGame::PacmanGame()
{

/*
    // ingame sounds
    beginning = new QMediaPlayer{};
    beginning->setMedia(QUrl("qrc:/Sounds/pacman_beginning.wav"));

    chomp = new QMediaPlayer{};
    chomp->setMedia(QUrl("qrc:/Sounds/pacman_chomp.wav"));

    eatfruit = new QMediaPlayer{};
    eatfruit->setMedia(QUrl("qrc:/Sounds/pacman_eatfruit.wav"));

    eatghost = new QMediaPlayer{};
    eatghost->setMedia(QUrl("qrc:/Sounds/pacman_eatghost.wav"));

    death = new QMediaPlayer{};
    death->setMedia(QUrl("qrc:/Sounds/pacman_death.wav"));
*/

    //std::string mapCe = ":/new/PacFiles/mapa";
    std::string mapCe = "/home/ariel/AI/mapa";
    int mapSelector = 1;                // napravicemo vec neko biranje
    mapCe += std::to_string(mapSelector) + ".txt";
    QString gameMap = QString::fromStdString(mapCe);
    QFile mapa{gameMap};
    mapa.open(QFile::ReadOnly | QFile::Text);
    QTextStream inMap{&mapa};

    char c;


    int x = 0, y = 0, broj_duha = 0;

    int direction;                      // ideja da u fajlu mapa imamo vec odredjen smer pekmena da bismo mogli
                                        // da usmerimo animaciju, taj broj da stoji pre svega ostalog
    inMap >> direction;
    QChar nula('0');                // 0 => bobica
    QChar kec('1');                 // 1 => zid
    QChar taraba('#');              // # => duh
    QChar pacPosition('P');         // P => pocetna pozicija
    QChar bigDot('B');              // B => velika bobica
    QChar emptySpace('=');          // '=' => prazan prostor
    QChar noviRed('\n');

    int spacing = 35;
    Wall *w1;
    Dot *tuf{};

    int mapaX, mapaY;
    inMap >> c;                         // kupi novi red posle ucitanog smera

    inMap >> c;
    mapaX = ((int)c - 48) * 10;
    inMap >> c;
    mapaX += (int)c - 48;

    inMap >> c;     //razmak
    inMap >> c;
    mapaY = ((int)c - 48)*10;
    inMap >> c;
    mapaY += (int)c - 48;
    inMap >> c;                         // kupi novi red posle ucitanih dimenzija mape


    std::vector <Node*> red(mapaX);


    while(!inMap.atEnd()){
        inMap >> c;
        if(c == nula || c == bigDot){
            // stavi bobicu, stavimo koliziju pekmena sa
            // bobicom da unisti bobicu i podesi skor
            tuf = new Dot(x,y, c);
            std::pair<int, int> par = {x,y};
            dots[par] = tuf;

            //=========================
            Node *node = new Node(x,y, true);
            red.push_back(node);
            //=========================
            x+=spacing;
        }
        else if(c == kec){
            w1 = new Wall(x,y,spacing,spacing);
            this->walls_and_borders.push_back(w1);

            //=========================
            Node *node = new Node(x,y, false);
            red.push_back(node);
            //=========================
            x+=spacing;
            //i++; // counts walls
        }
        else if(c == noviRed){
            this->mapa.push_back(red);
            x = 0;
            y+=spacing;
        }
        else if (c == taraba){
            ++broj_duha;
            this->ghost = new Ghost(x+2,y+2, broj_duha);
            this->ghosts.push_back(ghost);

            //=========================
            Node *node = new Node(x,y, true);
            red.push_back(node);
            //=========================
            x+=spacing;
        }
        else if(c == pacPosition){
            //this->pacman->setCurrentDirection(direction);
            this->pacman = new Pacman(x+2,y+2);

            //=========================
            Node *node = new Node(x,y, true);
            red.push_back(node);
            //=========================
            x+=spacing;
        }
        else if(c == emptySpace){

            //=========================
            Node *node = new Node(x,y, true);
            red.push_back(node);
            //=========================
            x+=spacing;
        }
    }
    //QTimer *timer = new QTimer(this);
    //QObject::connect(timer,SIGNAL(timeout()), this->ghost, aStar());
    //timer->start(3000);

}

PacmanGame::~PacmanGame()
{

}

Pacman* PacmanGame::getPacman(){
    return this->pacman;
}


int PacmanGame::getWidth(){
    QRect rec = QApplication::desktop()->screenGeometry();
    return rec.width();
}


int PacmanGame::getHeight(){
    QRect rec = QApplication::desktop()->screenGeometry();
    return rec.height();
}


//Wall* PacmanGame::getWall(){

//}

bool add_to_scene(QGraphicsScene &scene, Wall* zid){
    scene.addItem(zid);
    return true;
}

void PacmanGame::populateScene(QGraphicsScene &scene){
   // getWall();
    //QGraphicsItemGroup *group = new QGraphicsItemGroup{};

    for(auto x : this->walls_and_borders){
        scene.addItem(x);
        x->setBrush(Qt::darkGray);
    }

    for(auto x : this->ghosts){
        scene.addItem(x);
    }

    scene.addItem(this->pacman);


    for(auto x: this->dots){
        scene.addEllipse(x.second->getDot());
    }
    /*
    scene = std::accumulate(std::begin(this->walls_and_borders), std::end(this->walls_and_borders),
                    QGraphicsScene, add_to_scene);
    */

}



// for calculating the H cost
float PacmanGame::ManhattanDistance(int x, int y, Node dest){
    // |x1 - x2| + |y1 - y2|
    return  (float) fabs(x - dest.x) + (float) fabs(y - dest.y);
}



bool PacmanGame::isDestination(int x, int y, Node dest) {
    if (x == dest.x && y == dest.y) {
        return true;
    }
    return false;
}


bool PacmanGame::isValid(int x, int y){
    bool notWall = this->mapa[x][y]->isNotWall;
    if (notWall == true && (x >= 0 && y >= 0 && x<= MAX_X*35 && y <= MAX_Y*35 ) ) {
            return true;
    }
    return false;
}


/*
static bool isValid(int x, int y) { //If our Node is an obstacle it is not valid


       int id = x + y * (X_MAX / X_STEP);
       if (world.obstacles.count(id) == 0) {
           if (x < 0 || y < 0 || x >= (X_MAX / X_STEP) || y >= (Y_MAX / Y_STEP)) {
               return false;
           }
           return true;
       }
       return false;

   }
*/


// player is ghost and destination is going to be coordinates of pacman
std::vector<Node> PacmanGame::aStar(Node player, Node dest)
{
            std::vector<Node> empty;

// in our game destination is never going to be an obstacle
            if (isValid(dest.x , dest.y) == false) {
                std::cout << "Destination is an obstacle" << std::endl;
                return empty;
                //Destination is invalid
            }

            if (isDestination(player.x, player.y, dest)) {
                std::cout << "You are the destination" << std::endl;
                return empty;
                //You clicked on yourself
            }

            int spacing = 35;
            //bool closedList[(X_MAX / X_STEP)][(Y_MAX / Y_STEP)];
            bool closedList[MAX_X*spacing][MAX_Y*spacing];
            // i think that in closed list are all visited nodes
            // nullList are nodes that havent been seen or visited
            // openList are nodes that are seen but not visited




            //Initialize whole map


            //array<array < Node, (Y_MAX / Y_STEP)>, (X_MAX / X_STEP)> allMap;
            // spacin = 35 pa ybog toga a moze da se stavi samo x+= 35 a da ide do mapaX *35
            for (int x = 0; x < (24 * 35); x += 35) {
                for (int y = 0; y < (17 * 35); y += 35) {
                    //mapa[x][y]->fCost = FLT_MAX;
                    //mapa[x][y]->gCost = FLT_MAX;
                    //mapa[x][y]->hCost = FLT_MAX;
                    //mapa[x][y]->parentX = -1;
                    //mapa[x][y]->parentY = -1;
                    //mapa[x][y]->x = x;
                    //mapa[x][y]->y = y;
                    // zato sto smo to sredili u konstruktoru kad smo pracili mapu


                    // in the begining all nodes are not visited
                    closedList[x][y] = false;
               }
           }

            //Initialize our starting list
           int x = player.x;
           int y = player.y;
           // our ghost
           this->mapa[x][y]->fCost = 0.0;
           //mapa[x][y]->setFCost(0.0);
           this->mapa[x][y]->gCost = 0.0;
           this->mapa[x][y]->hCost = 0.0;
           this->mapa[x][y]->parentX = x;
           this->mapa[x][y]->parentY = y;

           std::vector<Node> openList;
           openList.emplace_back(*mapa[x][y]);
           bool destinationFound = false;


           // as long as the openList is not empty
           while (!openList.empty() && openList.size()<(MAX_X)*(MAX_Y)) {
                 Node node;
                 do {
                            //This do-while loop could be replaced with extracting the first
                            //element from a set, but you'd have to make the openList a set.
                            //To be completely honest, I don't remember the reason why I do
                            //it with a vector, but for now it's still an option, although
                            //not as good as a set performance wise.
                    float temp = FLT_MAX;
                    std::vector<Node>::iterator itNode;
                    for (std::vector<Node>::iterator it = openList.begin();
                        it != openList.end(); it = next(it)) {
                        auto n = it;
                        // treba uvesti za if it->IsNotWall == false da se ne uzima u obzir
                        if (n->fCost < temp) {
                            temp = n->fCost;
                            itNode = it;
                        }
                    }

                     // dobijamo node sa najmanjim fCost, mozda bolje da smo uzeli getF???
                     node = *itNode;
                     openList.erase(itNode);
                  }while(isValid(node.x, node.y) == false);
                    // moze da se zameni da ovde imamo

                        x = node.x;
                        y = node.y;
                        closedList[x][y] = true;    // oznacavmo da smo posetili node koji najmanji fCost

                        //For each neighbour starting from North-West to South-East
                        //for (int newX = -1; newX <= 1; newX++) {
                          //  for (int newY = -1; newY <= 1; newY++) {
                        for (int newX = -35; newX <= 35; newX += 35) {
                            for (int newY = -35; newY <= 35; newY+=35) {
                                //double gNew, hNew, fNew;
                                float gNew, hNew, fNew;
                                if (isValid(x + newX, y + newY)) {
                                    if (isDestination(x + newX, y + newY, dest))
                                    {
                                        //Destination found - make path
                                        mapa[x + newX][y + newY]->parentX = x;
                                        mapa[x + newX][y + newY]->parentY = y;
                                        destinationFound = true;
                                        return makePath(mapa, dest);
                                    }

                                    else if (closedList[x + newX][y + newY] == false)
                                    {
                                        gNew = node.gCost + 1.0;
                                        //ManhattanDistance(int x, int y, Node dest)
                                        hNew = ManhattanDistance(x + newX, y + newY, dest);
                                        fNew = gNew + hNew;
                                        // Check if this path is better than the one already present
                                        if (mapa[x + newX][y + newY]->fCost == FLT_MAX ||
                                            mapa[x + newX][y + newY]->fCost > fNew)
                                        {
                                            // Update the details of this neighbour node
                                            mapa[x + newX][y + newY]->fCost = fNew;
                                            mapa[x + newX][y + newY]->gCost = gNew;
                                            mapa[x + newX][y + newY]->hCost = hNew;
                                            mapa[x + newX][y + newY]->parentX = x;
                                            mapa[x + newX][y + newY]->parentY = y;
                                            openList.emplace_back(*mapa[x + newX][y + newY]);
                                        }
                                    }
                                }//end of if
                            }//end od for
                        }//end of for
                        }//end of while

                        if (destinationFound == false) {
                            std::cout << "Destination not found" << std::endl;
                            return empty;
                    }
                  return openList;
}



//array<array<Node, (Y_MAX / Y_STEP)>, (X_MAX / X_STEP)>

std::vector<Node> makePath(std::vector <std::vector <Node*> > map, Node dest) {
       // try {
            std::cout << "Found a path" << std::endl;
            int x = dest.x;
            int y = dest.y;
            std::stack<Node> path;
            std::vector<Node> usablePath;

            while (!(map[x][y]->parentX == x && map[x][y]->parentY == y)
                && map[x][y]->x != -1 && map[x][y]->y != -1)
            {
                path.push(*map[x][y]);
                int tempX = map[x][y]->parentX;
                int tempY = map[x][y]->parentY;
                x = tempX;
                y = tempY;

            }
            path.push(*map[x][y]);

            while (!path.empty()) {
                Node top = path.top();
                path.pop();
                usablePath.emplace_back(top);
            }
            return usablePath;
        //}catch(const exception& e){
        //    std::cout << e.what() << std::endl;
        //}
    }


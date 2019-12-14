#include "pacman.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QList>

#include "wall.h"


Pacman::Pacman()
{
    // ideja da li da imamo unique_ptr koji pokazuje na Pacman???
    setRect(100,100,100,100);
}



void Pacman::keyPressEvent(QKeyEvent *event){
    //treba u meni-ju korisnik da izabere da li ce da se krece na strelicu ili na jkli.. za sada ovako

    //kolizija sa zidom
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0,  n = colliding_items.size(); i<n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Wall))
            qDebug() << "Doslo je do kolizije izmedju Pacman-a i zida";
            //setPos(this->x(),this->y());
    }

    //kolizija sa Ghost-om


    if (event->key() == Qt::Key_Left){
        if (this->pos().x() > 0){
            setPos(x()-10,y());
        }
    }else if (event->key() == Qt::Key_Right){
        if (this->pos().x() + 100 < this->scene()->width()){
            setPos(x()+10,y());
        }
    }else if (event->key() == Qt::Key_Up){
        if (this->pos().y() > 0){
            setPos(x(),y()-10);
        }
    }else if (event->key() == Qt::Key_Down){
        if (this->pos().y() + 100 < this->scene()->height()){
            setPos(x(), y()+10);
        }
    }else if (event->key() == Qt::Key_J){ // left
        if (this->pos().x() > 0){
            setPos(x()-10,y());
        }
    }else if (event->key() == Qt::Key_L){ //right
        if (this->pos().x() + 100 < this->scene()->width()){
             setPos(x()+10,y());
        }
    }else if (event->key() == Qt::Key_I){ // up
        if (this->pos().y() > 0){
             setPos(x(),y()-10);
        }
    }else if (event->key() == Qt::Key_K){ //down
        if (this->pos().y() + 100 < this->scene()->height()){
            setPos(x(), y()+10);
        }
    }else if (event->key() == Qt::Key_Escape){
        qDebug() << "IZLAAAZ";
        QCoreApplication::quit();
    }
}

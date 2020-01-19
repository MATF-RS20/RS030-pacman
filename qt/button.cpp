#include "button.h"
#include <QBrush>
#include <QGraphicsTextItem>

Button::Button(QString name,int width, int height,QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{
    setRect(0,0,width,height);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // stavljamo da je button parent ove klase jer zelimo da kada obrisemo button da se obrise i text
    text = new QGraphicsTextItem(name,this);
    int xPos = this->rect().width()/2 - text->boundingRect().width()/2;
    int yPos = this->rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    this->setAcceptHoverEvents(true);

}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit this->clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

}

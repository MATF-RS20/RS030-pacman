#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>

class Button: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Button(QString name,int width, int height, QGraphicsItem *parent = NULL);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    //QString text;
    QGraphicsTextItem *text;
};

#endif // BUTTON_H

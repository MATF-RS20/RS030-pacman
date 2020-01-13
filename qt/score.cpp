#include "score.h"


Score::Score(QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{
    score = 0 ;

    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::setScore(int x)
{
    score+=x;
    setPlainText(QString("Score: ") + QString::number(score));

}

int Score::getScore(){
    return score;
}

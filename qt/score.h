#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem *parent =0, int scr = 0);
    void setScore(int x);
    int getScore();
private:
    int score;

};//end of class




#endif // SCORE_H

#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Score: \n") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",32));
}

void Score::increase(int scoreIncrement){
    score+=scoreIncrement;
    setPlainText(QString("Score: \n") + QString::number(score));
}

int Score::getScore(){
    return score;
}
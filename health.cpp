#include "health.h"
#include <QFont>

// health
Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the hp to 10
    health = 10;

    // draw the text
    setPlainText(QString("Health: \n") + QString::number(health));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",32));
}

void Health::change(int newHealth){
    health = newHealth;
    setPlainText(QString("Health: \n") + QString::number(health));
}

int Health::getHealth(){
    return health;
}


// level
CurrentLevel::CurrentLevel(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // initialize the hp to 10
    level = -1;

    // draw the text
    setPlainText(QString("Level: \n") + QString::number(level+1));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 32));
}

void CurrentLevel::change(int newLevel) {
    level = newLevel;
    setPlainText(QString("Level: \n") + QString::number(level+1));
}

int CurrentLevel::getLevel() {
    return level;
}
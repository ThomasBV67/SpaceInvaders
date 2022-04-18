#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem
{
public:
    Health(QGraphicsItem * parent=0);
    void change(int);
    int getHealth();
private:
    int health;
};

class CurrentLevel : public QGraphicsTextItem 
{
public:
    CurrentLevel(QGraphicsItem* parent = 0);
    void change(int);
    int getLevel();
private:
    int level;
};

#endif 
#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "enemy.h"
#include "player.h"
#include "defines.h"

#include <QGraphicsScene>
#include <QList>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    // public functions
    explicit GameScene(QObject* parent = nullptr);
    void generateEnemies(int rows, int cols); 
    void moveAliens();

    // public attributes
    QList<Enemy*> enemyList;
    Enemy* rightMostAlien;
    Enemy* leftMostAlien;
    int moveDirection = RIGHT;

public slots:


signals:

};

#endif // GAMESCENE_H

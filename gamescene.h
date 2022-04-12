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
    void generateEnemies(int rows, int cols); // TO DO

    // public attributes
    QList<Enemy*> enemyList;



signals:

};

#endif // GAMESCENE_H

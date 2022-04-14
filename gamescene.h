#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "enemy.h"
#include "player.h"
#include "bullet.h"
#include "defines.h"

#include <QgraphicsRectItem>
#include <QGraphicsScene>
#include <QList>
#include <QPalette>

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    // public functions
    explicit GameScene(QObject* parent = nullptr);
    void generateEnemies(int rows, int cols); 
    void moveAliens();
    void makePlayerShot();
    void keyPressEvent(QKeyEvent* keyEvent);
    void collision(Bullet* item);
    void collisionAll();
    
    template<typename T>
    void killItem(T* item);

    // public attributes
    QList<Enemy*> enemyList;
    QList<Bullet*> playerBulletsList;
    QList<Bullet*> enemyBulletsList;
    Enemy* rightMostAlien;
    Enemy* leftMostAlien;
    int moveDirection = RIGHT;
    Player* player1;
    QGraphicsRectItem* gameRect;
    bool paused = true;
    
    

public slots:
    void eventTimeToMove();
    void eventTimePlayer();
    void eventStart();
    void eventResume();
    void eventPause();

signals:
    void pause();
};

template<>
inline void GameScene::killItem<Bullet>(Bullet* item) 
{
    if (item->sens) {
        playerBulletsList.removeAll(item);
    }
    else {
        enemyBulletsList.removeAll(item);
    }
    removeItem(item);
    delete item;
}

template<>
inline void GameScene::killItem<QGraphicsItem>(QGraphicsItem* item) 
{
    enemyList.removeAll(item);
    removeItem(item);
    delete item;
}

#endif // GAMESCENE_H

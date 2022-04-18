#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "enemy.h"
#include "player.h"
#include "bullet.h"
#include "defines.h"
#include "shield.h"
#include "controller.h"
#include "score.h"
#include "health.h"

#include <QgraphicsRectItem>
#include <QGraphicsScene>
#include <QList>
#include <QPalette>
#include <QGraphicsTextItem>

struct Level
{
    int gridX = 10;
    int gridY = 4;
    float gameSpeedMod = 1.0;
    float enemySpeedMod = 1.0;
};

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
    QList<Enemy*> lowestEnemies;
    QList<Level> levels;
    Enemy* rightMostAlien;
    Enemy* leftMostAlien;
    int moveDirection = RIGHT;
    Player* player1;
    QGraphicsRectItem* gameRect;
    bool paused = true;
    DataController dataController;
    Score* score;
    Health* hp;
    CurrentLevel* currentLevel;
    
    

public slots:
    void eventTimeToMove();
    void eventTimePlayer(DataController);
    void eventStart();
    void eventResume();
    void eventPause();
    void controllerConnected();
signals:
    void pause();
    void updateGameSpeed(int);

private:
    void setUpShields();
    void updateLeftRightAlien();
    QGraphicsRectItem* GameOverZone;
    void checkInvaderTouchDown();
    void initLevels();
    void setLevel(int);
    void levelUp();
    void invaderAttack(int attackRate);
    bool gameOver;
    int level=0;
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
inline void GameScene::killItem<Enemy>(Enemy* item) 
{
    enemyList.removeAll(item);
    removeItem(item);
    delete item;
    updateLeftRightAlien();
}
template<>
inline void GameScene::killItem<Shield>(Shield* item)
{
    if (!item->getHit()) {
        removeItem(item);
        delete item;
    }
}
// backout function si il y a un probleme
template<>
inline void GameScene::killItem<QGraphicsItem>(QGraphicsItem* item)
{
    removeItem(item);
    delete item;
}
#endif // GAMESCENE_H



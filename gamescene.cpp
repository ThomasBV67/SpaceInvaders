#include "gamescene.h"

GameScene::GameScene(QObject* parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void GameScene::generateEnemies(int rows, int cols)
{
    Enemy* tempEnemy;
    int tempX, tempY, divX, divY;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            divX = (WINDOW_WIDTH - (BORDER_WIDTH_SIDE * 2) - INVADER_WIDTH) / cols;
            tempX = BORDER_WIDTH_SIDE + j * divX;

            divY = (WINDOW_HEIGHT - (BORDER_WIDTH_TOP * 2)) / rows;
            tempY = BORDER_WIDTH_TOP + i * divY;

            tempEnemy = new Enemy(tempX,tempY,j,i);
            enemyList.append(tempEnemy);
            addItem(tempEnemy);
        }
    }
}
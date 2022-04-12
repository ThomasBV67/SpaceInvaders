#include "gamescene.h"

GameScene::GameScene(QObject* parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    //connect(this, SIGNAL(timeToMove()), SLOT(eventTimeToMove()));
}

void GameScene::generateEnemies(int cols, int rows)
{
    Enemy* tempEnemy;
    int tempX, tempY, divX, divY;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            divX = (WINDOW_WIDTH - (BORDER_WIDTH_SIDE * 2)) / cols;
            tempX = BORDER_WIDTH_SIDE + j * divX;

            divY = (WINDOW_HEIGHT - (BORDER_WIDTH_TOP * 2)) / rows;
            tempY = BORDER_WIDTH_TOP + i * divY;

            tempEnemy = new Enemy(tempX,tempY,j,i);
            enemyList.append(tempEnemy);
            addItem(tempEnemy);
        }
    }
    leftMostAlien = enemyList[0];
    rightMostAlien = enemyList[cols-1];

}

void GameScene::moveAliens()
{
    int tempX, tempY;

    if (rightMostAlien->x() + ENEMY_MOVE_INCREMENT > X_RIGHT_LIMIT)
    {
        if (moveDirection == RIGHT)
        {
            moveDirection = DOWN;
        }
        else if (moveDirection == DOWN)
        {
            moveDirection = LEFT;
        }
    }
    else if (leftMostAlien->x() - ENEMY_MOVE_INCREMENT < X_LEFT_LIMIT)
    {
        if (moveDirection == LEFT)
        {
            moveDirection = DOWN;
        }
        else if (moveDirection == DOWN)
        {
            moveDirection = RIGHT;
        }
    }

    for(int i = 0; i < enemyList.length(); i++)
    {
        tempX = enemyList[i]->x();
        tempY = enemyList[i]->y();

        if (moveDirection == RIGHT)
        {
            tempX += ENEMY_MOVE_INCREMENT;
        }
        else if (moveDirection == LEFT)
        {
            tempX -= ENEMY_MOVE_INCREMENT;
        }
        else if (moveDirection == DOWN)
        {
            tempY += ENEMY_MOVE_INCREMENT;
        }

        enemyList[i]->setX(tempX);
        enemyList[i]->setY(tempY);
    }
}

void GameScene::eventTimeToMove()
{
    moveAliens();
}


#include "gamescene.h"

GameScene::GameScene(QObject* parent)
    : QGraphicsScene(parent)
{
    setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    player1 = new Player(this);
    gameRect = new QGraphicsRectItem(BORDER_WIDTH_SIDE, BORDER_WIDTH_TOP, WINDOW_WIDTH - BORDER_WIDTH_SIDE, WINDOW_HEIGHT - 2 * BORDER_WIDTH_TOP);
    player1->setGameRect(gameRect);
    gameRect->setZValue(10);
    addItem(gameRect);
    addItem(player1);
}

void GameScene::generateEnemies(int cols, int rows)
{
    Enemy* tempEnemy;
    int tempX, tempY, divX, divY;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            divX = (WINDOW_WIDTH - (BORDER_WIDTH_SIDE * 2)) / (cols+1);
            tempX = BORDER_WIDTH_SIDE + j * divX;

            divY = 50;
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

    if (rightMostAlien->x() + ENEMY_MOVE_INCREMENT + INVADER_WIDTH > X_RIGHT_LIMIT)
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

void GameScene::makePlayerShot()
{
    if (playerBulletsList.size() < 3) {
        playerBulletsList.append(player1->shoot());
    }


}

void GameScene::keyPressEvent(QKeyEvent* keyEvent)
{
    if (keyEvent->key() == Qt::Key_Space) {
        makePlayerShot();
    }
    if (keyEvent->key() == Qt::Key_Left) {
        player1->speed -= 1;
    }
    if (keyEvent->key() == Qt::Key_Right) {
        player1->speed += 1;
    }
    if (keyEvent->key() == Qt::Key_P) {
        collision(playerBulletsList[0]);
    }
}

void GameScene::collision(Bullet* item)
{
    QList<QGraphicsItem*>list = collidingItems(item, Qt::IntersectsItemShape);
    if (list.isEmpty()) {
        killItem(item);
    }
    if (list.size() == 2) {
        int type = list[1]->type();
        switch (type) {
        case BULLET_TYPE:
            killItem(item);
            killItem(list[1]);
            break;
        case INVADER_TYPE:
            killItem(item);
            killItem(list[1]);
            break;
        case PLAYER_TYPE:
            killItem(item);
            //player1->hit(); TO DO
        default:
            break;
        }
    }
}

void GameScene::collisionAll()
{
    for (int i = 0; i < playerBulletsList.size(); i++) {
        collision(playerBulletsList[i]);
    }
    for (int i = 0; i < enemyBulletsList.size(); i++) {
        collision(enemyBulletsList[i]);
    }
}

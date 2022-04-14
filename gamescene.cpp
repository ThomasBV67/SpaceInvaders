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

    // sets background color to black
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::black);
    this->setPalette(palette);
}
/// <summary>
/// This function generates enemies in a grid patern of size cols x rows.
/// The enemies are also added to the scene and to a list containing all
/// the living enemies.
/// </summary>
/// <param name="cols">number of collumns of enemies to be generated</param>
/// <param name="rows">number of rows of enemies to be generated</param>
void GameScene::generateEnemies(int cols, int rows)
{
    // creating temp variables
    Enemy* tempEnemy;
    int tempX, tempY, divX, divY;

    // imbricated loops to create every enemy
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // horizontally separate the enemies by a number of pixel relative to the amount of enemies
            divX = (WINDOW_WIDTH - (BORDER_WIDTH_SIDE * 2)) / (cols+1);
            tempX = BORDER_WIDTH_SIDE + j * divX;

            // vertical separation is a fixed value
            divY = VERTICAL_SPREAD;
            tempY = BORDER_WIDTH_TOP + i * divY;

            // generate enemies and add to list and scene
            tempEnemy = new Enemy(tempX,tempY,j,i);
            enemyList.append(tempEnemy);
            addItem(tempEnemy);
        }
    }

    // values used to know how wide the aliens can travel horizontally 
    // before hiting a wall
    leftMostAlien = enemyList[0];
    rightMostAlien = enemyList[cols-1];

}

/// <summary>
/// This function moves all aliens on screen by a set amout of pixels in
/// the direction they need to go to follow the game's logic
/// </summary>
void GameScene::moveAliens()
{
    int tempX, tempY;
    
    // making sure aliens are still when paused
    if (enemyList.isEmpty()||paused)
    {
        return;
    }

    // change direction of aliens if right side is reached
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
    // change direction of aliens if left side is reached
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

    // move loop
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
            tempY += ENEMY_DOWN_INCREMENT;
        }

        enemyList[i]->setX(tempX);
        enemyList[i]->setY(tempY);
    }
}

/// <summary>
/// This slot is called by the game speed thread and makes bullets and aliens move
/// </summary>
void GameScene::eventTimeToMove()
{
    // making sure nothing moves when the game is paused
    if (paused)
    {
        return;
    }

    moveAliens();
    advance();
    collisionAll();
}

/// <summary>
/// This function is used to shoot if the player has bullets left
/// </summary>
void GameScene::makePlayerShot()
{
    // player dosent shoot while paused
    if (paused)
    {
        return;
    }

    if (playerBulletsList.size() < 3) {
        playerBulletsList.append(player1->shoot());
    }
}

/// <summary>
/// This event deals with all keyboard input
/// </summary>
/// <param name="keyEvent"></param>
void GameScene::keyPressEvent(QKeyEvent* keyEvent)
{
    // ignore input when paused
    if (paused)
    {
        return;
    }

    // Space shoots
    if (keyEvent->key() == Qt::Key_Space) {
        makePlayerShot();
    }
    // Left arrow speeds up player towards the left
    else if (keyEvent->key() == Qt::Key_Left) {
        player1->speed -= 1;
    }
    // Right arrow speeds up player towards the right
    else if (keyEvent->key() == Qt::Key_Right) {
        player1->speed += 1;
    }
    // P
    else if (keyEvent->key() == Qt::Key_P) {
        collision(playerBulletsList[0]);
    }
    // Escape key pauses the game and opens the pause menu
    else if (keyEvent->key() == Qt::Key_Escape)
    {
        emit pause();
        paused = true;
    }
}

/// <summary>
/// 
/// </summary>
/// <param name="item"></param>
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

/// <summary>
/// 
/// </summary>
void GameScene::collisionAll()
{
    for (int i = 0; i < playerBulletsList.size(); i++) {
        collision(playerBulletsList[i]);
    }
    for (int i = 0; i < enemyBulletsList.size(); i++) {
        collision(enemyBulletsList[i]);
    }
}

/// <summary>
/// 
/// </summary>
void GameScene::eventTimePlayer()
{
    player1->customAdvance();
}

/// <summary>
/// This slot is called when the game is started by the main menu
/// </summary>
void GameScene::eventStart()
{
    // start game with 10x4 board of enemies
    generateEnemies(10, 4);
    paused = false;
}

/// <summary>
/// This slot is called when the game is paused
/// </summary>
void GameScene::eventPause()
{
    paused = true;
}

/// <summary>
/// This slot is called when pressing the resume button in the pause menu
/// </summary>
void GameScene::eventResume()
{
    paused = false;
}

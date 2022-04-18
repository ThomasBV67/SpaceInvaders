#include "gamescene.h"

GameScene::GameScene(QObject* parent)
    : QGraphicsScene(parent)
{
    gameOver = false;
    setSceneRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    player1 = new Player(this);
    gameRect = new QGraphicsRectItem(X_LEFT_LIMIT, BORDER_WIDTH_TOP, WINDOW_WIDTH-X_LEFT_LIMIT, WINDOW_HEIGHT - 2 * BORDER_WIDTH_TOP);
    player1->setGameRect(gameRect);
    gameRect->setZValue(10);
    gameRect->setPen(QPen(Qt::white,3));
    addItem(gameRect);
    addItem(player1);
    setUpShields();

    // set up of gameoverzone
    GameOverZone = new QGraphicsRectItem(X_LEFT_LIMIT, WINDOW_HEIGHT - 200, WINDOW_WIDTH - X_LEFT_LIMIT, 200);
    GameOverZone->hide();
    addItem(GameOverZone);

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
            divX = (WINDOW_WIDTH - (X_LEFT_LIMIT)) / (cols+1);
            tempX = X_LEFT_LIMIT + j * divX;

            // vertical separation is a fixed value
            divY = VERTICAL_SPREAD;
            tempY = BORDER_WIDTH_TOP + i * divY;

            // generate enemies and add to list and scene
            tempEnemy = new Enemy(tempX,tempY,j,i);
            enemyList.append(tempEnemy);
            addItem(tempEnemy);
            if (i == rows - 1)
            {
                lowestEnemies.append(tempEnemy);
            }
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
            checkInvaderTouchDown();
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
    invaderAttack(10);

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
    // debug
    else if (keyEvent->key() == Qt::Key_P) {
        player1->dash(true);
    }
    //debug
    else if (keyEvent->key() == Qt::Key_O) {
        player1->dash(false);
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
    Bullet* dynamicClassBullet;
    Enemy* dynamicClassEnemy;
    Shield* dynamcClassShield;
    QList<QGraphicsItem*>list = collidingItems(item, Qt::IntersectsItemShape);
    if (list.isEmpty()) {
        killItem(item);
    }
    for (int i = 0; i < list.size();i++) {
        int type = list[i]->type();

        switch (type) {
        case BULLET_TYPE:
            dynamicClassBullet = dynamic_cast<Bullet*>(list[i]);
            killItem(item);
            killItem(dynamicClassBullet);
            break;

        case INVADER_TYPE:
            dynamicClassEnemy = dynamic_cast<Enemy*>(list[i]);
            killItem(item);
            // changing the pointer to the new rightmost alien if it dies
            if (dynamicClassEnemy->x() == rightMostAlien->x() && dynamicClassEnemy->y() == rightMostAlien->y())
            {
                int maxX = 0;
                Enemy* newRightMost;
                for (int k = 0; k < enemyList.count(); k++)
                {
                    if (enemyList[k]->x() > maxX)
                    {
                        maxX = enemyList[k]->x();
                        newRightMost = enemyList[k];
                    }
                }
                rightMostAlien = newRightMost;
            }

            // changing the pointer to the new leftmost alien if it dies
            else if (dynamicClassEnemy->x() == leftMostAlien->x() && dynamicClassEnemy->y() == leftMostAlien->y())
            {
                int minX = 10000;
                Enemy* newleftMost;
                for (int k = 0; k < enemyList.count(); k++)
                {
                    if (enemyList[k]->x() < minX)
                    {
                        minX = enemyList[k]->x();
                        newleftMost = enemyList[k];
                    }
                }
                leftMostAlien = newleftMost;
            }

            // update the lowest enemies list if one dies
            if (lowestEnemies.contains(dynamicClassEnemy))
            {
                lowestEnemies.removeOne(dynamicClassEnemy);
                int maxY = 0;
                Enemy* newLowest = nullptr;

                for (int k = 0; k < enemyList.count(); k++)
                {
                    if (enemyList[k]->x() == dynamicClassEnemy->x() && enemyList[k]->y() > maxY)
                    {
                        maxY = enemyList[k]->y();
                        newLowest = enemyList[k];
                    }
                }
                if (newLowest != nullptr)
                {
                    lowestEnemies.append(newLowest);
                }
            }
            killItem(dynamicClassEnemy);
            break;

        case PLAYER_TYPE:
            killItem(item);
            //player1->hit(); TO DO
            break;

        case SHIELD_TYPE:
            dynamcClassShield = dynamic_cast<Shield*>(list[i]);
            killItem(item);
            killItem(dynamcClassShield);
            break;

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
/// This updates the variables leftmostAlien and rightmostAlien
/// </summary>
void GameScene::updateLeftRightAlien()
{
    if (!enemyList.contains(leftMostAlien)) {
        int max = 100;
        for (int i = 0; i < enemyList.size(); i++) {
            if (enemyList[i]->gridPosition.x <= max) {
                max = enemyList[i]->gridPosition.x;
                leftMostAlien = enemyList[i];
            }
        }
    }
    if (!enemyList.contains(rightMostAlien)) {
        int min = -1;
        for (int i = 0; i < enemyList.size(); i++) {
            if (enemyList[i]->gridPosition.x >= min) {
                min = enemyList[i]->gridPosition.x;
                rightMostAlien = enemyList[i];
            }
        }
    }
}
/// <summary>
/// This function is called when the scene is started
/// the shields are created and added to the scene
/// </summary>
void GameScene::setUpShields()
{
    for (int i = 0; i < 4; i++) {
        //((WINDOW_WIDTH - X_LEFT_LIMIT) - 4 * SHIELD_WIDTH) / 5
            new Shield(X_LEFT_LIMIT+ ((WINDOW_WIDTH - X_LEFT_LIMIT) - 4 * SHIELD_WIDTH) / 5 + i*((((WINDOW_WIDTH - X_LEFT_LIMIT) - 4 * SHIELD_WIDTH) / 5)+ SHIELD_WIDTH ), WINDOW_HEIGHT- 200,this);
    }
}

void GameScene::checkInvaderTouchDown()
{
    QList<QGraphicsItem*>list = collidingItems(GameOverZone, Qt::IntersectsItemShape);
    for (int item = 0; item < list.size(); item++) {
        if (list[item]->type() == INVADER_TYPE) {
            gameOver = true;
            paused = true;
            // gameOver Menu ... score systeme...
        }
    }
}

void GameScene::invaderAttack(int attackRate)
{
    int value = rand() % 100 + 1;
    if (value <= attackRate) {
        int selectedShooter = rand() % lowestEnemies.size();
        enemyBulletsList.append(lowestEnemies[selectedShooter]->shoot());
    }
}

/// <summary>
/// This slot is called when pressing the resume button in the pause menu
/// </summary>
void GameScene::eventResume()
{
    paused = false;
}

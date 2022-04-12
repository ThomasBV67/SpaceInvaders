#include "enemy.h"

Enemy::Enemy(int coorX, int coorY, int gridX, int gridY, QWidget* parent)
{
	setPixmap(QPixmap(":/images/invader.png"));

	setX(coorX);
	setY(coorY);

	gridPosition.x = gridX;
	gridPosition.y = gridY;
}
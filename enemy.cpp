#include "enemy.h"

Enemy::Enemy(int coorX, int coorY, int gridX, int gridY, QWidget* parent)
{
	// sets the shown image for enemies as invader.png
	setPixmap(QPixmap(":/images/invader.png"));

	// sets the values as the inputs
	setX(coorX);
	setY(coorY);
	gridPosition.x = gridX;
	gridPosition.y = gridY;
}
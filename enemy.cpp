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

Bullet* Enemy::shoot()
{
	unsigned int xVal = 0;
	unsigned int yVal = 0;
	xVal = x();
	yVal = y();
	QGraphicsScene* thisScene = scene();
	Bullet* bullet = new Bullet(false, xVal, yVal, thisScene, this);
	return bullet;
}

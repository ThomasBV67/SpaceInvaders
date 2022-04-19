#include "bullet.h"

Bullet::Bullet(bool inSens, int x, int y, QGraphicsScene* scene, QGraphicsItem* parent) {
	sens = inSens;
	setPixmap(QPixmap(":/images/bullet.png"));
	if (sens) {
		setPos(x + PLAYER_WIDTH / 2 -1, y - BULLET_HEIGHT);
	}
	else {
		setPos(x + INVADER_WIDTH / 2 -1, y + INVADER_HEIGHT);
	}
	if (scene == nullptr)
	{

	}
	scene->addItem(this);
}

void Bullet::advance(int step)
{
	if (!step)
		return;

	if (sens) {
		moveBy(0,  -BULLET_SPEED);
	}
	else {
		moveBy(0, BULLET_SPEED);
	}
	
}

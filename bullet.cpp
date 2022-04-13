#include "bullet.h"

Bullet::Bullet(bool inSens, QGraphicsItem* parent) {
	sens = inSens;
	setPixmap(QPixmap(":/images/bullet.png"));
	if (sens) {
		setPos(parent->x() + PLAYER_WIDTH / 2 -1, parent->y() - BULLET_HEIGHT);
	}
	else {
		setPos(parent->x() + INVADER_WIDTH / 2 -1, parent->y() + INVADER_HEIGHT);
	}

	parent->scene()->addItem(this);
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

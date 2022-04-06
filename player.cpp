#include "player.h"

void Player::keyPressEvent(QKeyEvent* event)
{
	qDebug() << event->key();
	if (event->key() == Qt::Key_Left &&
		x()>=10)
	{
		setPos(x() - 10, y());
	}
	else if (event->key() == Qt::Key_Right &&
		x() <= scene()->width() - rect().width())
	{
		setPos(x() + 10, y());
	}
}
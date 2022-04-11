#include "player.h"

Player::Player(QWidget* parent)
{
	setPixmap(QPixmap(":/images/player.png"));
}

/*void Player::keyPressEvent(QKeyEvent* event)
{
	qDebug() << event->key();
	if (event->key() == Qt::Key_Left &&
		x()>=10)
	{
		setPos(x() - 10, y());
	}
	else if (event->key() == Qt::Key_Right &&
		x() <= scene()->width())
	{
		setPos(x() + 10, y());
	}
}*/


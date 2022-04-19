#include "special.h"

Special::Special(qreal inX, qreal inY, QGraphicsScene* parent) {
	setPixmap(QPixmap(":/images/special.png"));
	setPos(inX, inY);
	parent->addItem(this);
}

void Special::advance(int step)
{
	moveBy(-3, 0);
	QList<QGraphicsItem*>list = collidingItems(Qt::ContainsItemShape);
	if (list.isEmpty()) {
		scene()->removeItem(this);
		delete this;
	}
}


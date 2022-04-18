#include "shield.h"

Shield::Shield(qreal inX, qreal inY, QGraphicsScene* parent) {
	setPixmap(QPixmap(":/images/shield.png"));
	hitPoints = SHIELD_BASEHP;
	setPos(inX, inY);
	parent->addItem(this);
}

bool Shield::getHit() {
	hitPoints--;
	opac = float(hitPoints)/ float(SHIELD_BASEHP);
	setOpacity(opac);
	if (hitPoints <= 0) {
		return false;
	}
	else
		return true;
}
#include "shield.h"

Shield::Shield(qreal inX, qreal inY, QGraphicsScene* parent) {
	setPixmap(QPixmap(":/images/shield.png"));
	hitPoints = SHIELD_BASEHP;
	setPos(inX, inY);
	parent->addItem(this);
}

bool Shield::getHit() {
	hitPoints--;
	//setGraphicsEffect(QGraphicsOpacityEffect::setOpacity(hitPoints / SHIELD_BASEHP)); 
	// si le shield na plus de hp false est retourne
	if (hitPoints <= 0) {
		return false;
	}
	else
		return true;
}
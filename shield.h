#ifndef SHIELD_H
#define SHIELD_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsOpacityEffect>
#include <QGraphicsEffect>

#include "defines.h"


class Shield : public QGraphicsPixmapItem
{
public:
	enum { Type = UserType + 4 };
	int type() const override {
		return Type;
	}
	Shield(qreal inX, qreal inY, QGraphicsScene* parent = nullptr);
	bool getHit();
private:
	int hitPoints;
	float opac;
};


#endif // !SHIELD_H
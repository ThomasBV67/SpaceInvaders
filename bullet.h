#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include "defines.h"
#include <QGraphicsRectItem>

class Bullet : public QGraphicsPixmapItem
{
public:
	enum { Type = UserType + 2 };
	int type() const override {
		return Type;
	}
	Bullet(bool inSens, QGraphicsItem* parent);
	bool sens;
protected:
	void advance(int step) override;
};
#endif
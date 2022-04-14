#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "defines.h"
#include "bullet.h"

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsRectItem>

class Player : public QGraphicsPixmapItem
{
public:
	enum { Type = UserType + 3 };
	int type() const override {
		return Type;
	}
	Player(QGraphicsScene* parent = nullptr);
	void keyPressEvent(QKeyEvent* event);
	int speed;
	void updatePlayer();
	void setGameRect(QGraphicsRectItem* inGameRect);
	Bullet* shoot();
	QPointF lastpos;
	void customAdvance();
private:
	QGraphicsRectItem* gameRect;
	QGraphicsScene* parent;

};
#endif
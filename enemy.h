#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>
#include "bullet.h"

struct GridPosition
{
	int x;
	int y;
};

class Enemy : public QGraphicsPixmapItem
{
public:
	enum { Type = UserType + 1 };
	int type() const override {
		return Type;
	}
	Enemy(int coorX, int coorY, int gridX, int gridY, QWidget* parent = NULL);
	Bullet* shoot();
	//void keyPressEvent(QKeyEvent* event);
	GridPosition gridPosition;

private:

};



#endif	
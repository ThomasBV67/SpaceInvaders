#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>

class Enemy : public QGraphicsPixmapItem
{
public:
	Enemy(int coorX, int coorY, int gridX, int gridY, QWidget* parent = NULL);
	//void keyPressEvent(QKeyEvent* event);
	GridPosition gridPosition;
private:

};

struct GridPosition
{
	int x;
	int y;
};

#endif	
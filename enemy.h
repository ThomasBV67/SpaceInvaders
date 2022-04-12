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
	Enemy(QWidget* parent = NULL);
	//void keyPressEvent(QKeyEvent* event);
private:

};

#endif	
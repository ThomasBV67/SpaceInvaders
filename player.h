#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QEvent>
#include <QKeyEvent>
#include <QGraphicsScene>

class Player : public QGraphicsRectItem
{
public:
	Player() {};
	void keyPressEvent(QKeyEvent* event);
private:

};
#endif
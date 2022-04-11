#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>

class Player : public QGraphicsPixmapItem
{
public:
	Player(QWidget* parent = NULL);
	//void keyPressEvent(QKeyEvent* event);
private:

};
/*
class Player : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	Player(QWidget* parent = NULL);
	//void keyPressEvent(QKeyEvent* event);
public slots:

private:

};
*/
#endif
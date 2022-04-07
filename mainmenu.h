#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>

class MainMenu : public QGraphicsScene
{
public:
	MainMenu();

	QGraphicsRectItem* goBtn;
	QGraphicsRectItem* quitBtn;
private:
	
};
#endif
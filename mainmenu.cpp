#include "mainmenu.h"

MainMenu::MainMenu()
{
	goBtn = new QGraphicsRectItem();
	goBtn->setRect(0, 0, 100, 50);

	quitBtn = new QGraphicsRectItem();
	quitBtn->setRect(0, 200, 100, 50);

	addItem(goBtn);
	addItem(quitBtn);
}
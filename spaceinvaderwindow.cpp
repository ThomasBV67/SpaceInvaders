#include "spaceinvaderwindow.h"

SpaceInvaderWindow::SpaceInvaderWindow(QWidget* parent)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(1024, 768);

	mainMenu = new MainMenu();
	mainMenu->setSceneRect(0, 0, 1024, 768);
	setScene(mainMenu);

	show();
}


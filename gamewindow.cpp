#include "gamewindow.h"

GameWindow::GameWindow(QWidget* parent)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(1024, 768);

	show();
}


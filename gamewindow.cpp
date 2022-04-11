#include "gamewindow.h"

GameWindow::GameWindow(QWidget* parent)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(WINDOW_WIDTH, 768);

	show();
}


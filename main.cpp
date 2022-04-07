#include "spaceinvaderwindow.h"
#include "mainmenu.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QStackedWidget>
#include <QMainWindow>

SpaceInvaderWindow* game;

int main(int argc, char *argv[])
{
	//Init app
	QApplication a(argc, argv);

	QStackedWidget* sWidget = new QStackedWidget();

	MainMenu* mainMenu = new MainMenu();

	sWidget->addWidget(mainMenu);

	sWidget->setCurrentWidget(mainMenu);
	sWidget->setFixedSize(1000, 600);
	sWidget->show();

	return a.exec();
}

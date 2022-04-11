#include "gamewindow.h"
#include "mainmenu.h"
#include "defines.h"
#include "player.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QStackedWidget>
#include <QMainWindow>

GameWindow* game;

int main(int argc, char *argv[])
{
	//Init app
	QApplication a(argc, argv);
		
	// setup a stacked widget to allow different pages
	QStackedWidget* sWidget = new QStackedWidget();

	// init all pages
	MainMenu* mainMenu = new MainMenu();
	//PauseMenu* pauseMenu = new PauseMenu(); TO DO
	//GameWindow* gameWindow = new GameWindow(); TO DO

	Player* player = new Player();
	QGraphicsScene* scene = new QGraphicsScene();
	scene->addItem(player);
	QGraphicsView* view = new QGraphicsView(scene);

	// adding all pages to the stacked widget
	sWidget->addWidget(mainMenu);
	sWidget->addWidget(view);
	//sWidget->addWidget(pauseMenu); TO DO
	//sWidget->addWidget(gameWindow); TO DO

	// Fix the size of the window and show the mainMenu
	sWidget->setCurrentWidget(view);
	sWidget->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	sWidget->show();

	return a.exec();
}

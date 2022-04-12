#include "gamewindow.h"
#include "mainmenu.h"
#include "defines.h"
#include "player.h"
#include "inputthread.h"
#include "enemy.h"
#include "gamescene.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QStackedWidget>
#include <QMainWindow>

GameWindow* game;

int main(int argc, char *argv[])
{
	bool window = 0;
	//Init app
	QApplication a(argc, argv);
	// setup a stacked widget to allow different pages
	QStackedWidget* sWidget = new QStackedWidget();

	// init all pages
	MainMenu* mainMenu = new MainMenu();
	//PauseMenu* pauseMenu = new PauseMenu(); TO DO
	GameWindow* gameWindow = new GameWindow(); 

	Player* player = new Player();
	//Enemy* enemy = new Enemy();

	QGraphicsScene* scene = new QGraphicsScene();
	GameScene* sceneTest = new GameScene();

	sceneTest->generateEnemies(4, 10);

	scene->addItem(player);

	gameWindow->setScene(sceneTest);

	// adding all pages to the stacked widget
	sWidget->addWidget(mainMenu);
	sWidget->addWidget(gameWindow);
	//sWidget->addWidget(pauseMenu); TO DO

	// Fix the size of the window and show the mainMenu
	sWidget->setCurrentWidget(gameWindow);
	sWidget->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	sWidget->show();

	InputThread inputThread;
	inputThread.start();

	return a.exec();
}

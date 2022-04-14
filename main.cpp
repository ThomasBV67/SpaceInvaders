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

	GameScene* sceneTest = new GameScene();

	gameWindow->gameScene->generateEnemies(10, 4);

	// adding all pages to the stacked widget
	sWidget->addWidget(mainMenu);
	sWidget->addWidget(gameWindow);
	//sWidget->addWidget(pauseMenu); TO DO

	// Fix the size of the window and show the mainMenu
	sWidget->setCurrentWidget(gameWindow);
	sWidget->setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	sWidget->show();

	return a.exec();
}

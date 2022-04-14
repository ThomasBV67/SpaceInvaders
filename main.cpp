#include "gamewindow.h"
#include "mainmenu.h"
#include "defines.h"
#include "player.h"
#include "inputthread.h"
#include "enemy.h"
#include "gamescene.h"
#include "stackedw.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QStackedWidget>
#include <QMainWindow>


/// <summary>
/// This application is a spaceinvader inspired game.
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
int main(int argc, char *argv[])
{
	//Init app
	QApplication a(argc, argv);

	// setup a stacked widget to allow different pages
	StackedW* game = new StackedW();

	// setup a clean way to exit the game
	QObject::connect(game->mainMenu->quitBtn, SIGNAL(clicked()), &a, SLOT(quit()));
	QObject::connect(game->pauseMenu->quitBtn, SIGNAL(clicked()), &a, SLOT(quit()));

	return a.exec();
}

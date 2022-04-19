#pragma once
#include "gamewindow.h"
#include "mainmenu.h"
#include "defines.h"
#include "player.h"
#include "inputthread.h"
#include "enemy.h"
#include "gamescene.h"
#include "pausemenu.h"
#include "gameovermenu.h"

#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtCore>
#include <QStackedWidget>

class StackedW : public QStackedWidget
{
	Q_OBJECT
public:
	StackedW();
	~StackedW();

	MainMenu* mainMenu;
	GameWindow* gameWindow;
	PauseMenu* pauseMenu;
	GameOverMenu* gameOverMenu;

private:

public slots:
	void goToGame();
	void goToMain();
	void goToPause();
	void goToGameOver(int);
	void closeWindow();
signals:

};
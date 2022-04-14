#pragma once
#include "gamewindow.h"
#include "mainmenu.h"
#include "defines.h"
#include "player.h"
#include "inputthread.h"
#include "enemy.h"
#include "gamescene.h"
#include "pausemenu.h"

#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtCore>
#include <QStackedWidget>

class StackedW : public QStackedWidget, public QObject
{
	Q_OBJECT
public:
	StackedW();
	~StackedW();

	MainMenu* mainMenu;
	GameWindow* gameWindow;
	PauseMenu* pauseMenu;

private:

public slots:
	void goToGame();
	void goToPause();
	void closeWindow();
signals:

};
#include "gamewindow.h"

GameWindow::GameWindow(QWidget* parent)
{
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(WINDOW_WIDTH, 768);

	gameScene = new GameScene();
	inputThread = new InputThread();
	threadObj = new QThread();

	inputThread->moveToThread(threadObj);
	connect(inputThread, SIGNAL(error(QString)), this, SLOT(errorString(QString)));
	connect(threadObj, SIGNAL(started()), inputThread, SLOT(process()));
	connect(inputThread, SIGNAL(finished()), threadObj, SLOT(quit()));
	connect(inputThread, SIGNAL(finished()), inputThread, SLOT(deleteLater()));
	connect(inputThread, SIGNAL(moveAliens()), gameScene, SLOT(eventTimeToMove()));
	connect(threadObj, SIGNAL(finished()), threadObj, SLOT(deleteLater()));

	threadObj->start();

	setScene(gameScene);
	show();
}

GameWindow::~GameWindow()
{
	delete inputThread;
	delete threadObj;
	delete gameScene;
}


#include "gamewindow.h"

GameWindow::GameWindow(QWidget* parent)
{
	// force size of game window
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// init the scene
	gameScene = new GameScene();
	
	// init the QObjets for the threads
	inputThread = new InputThread();
	gameThread = new GameSpeedThread();

	// init the threads
	threadInputs = new QThread();
	threadLogic = new QThread();

	// link the objects to their threads
	inputThread->moveToThread(threadInputs);
	gameThread->moveToThread(threadLogic);

	// base connects for inputs
	connect(threadInputs, SIGNAL(started()), inputThread, SLOT(process()));
	connect(inputThread, SIGNAL(finished()), threadInputs, SLOT(quit()));
	connect(inputThread, SIGNAL(finished()), inputThread, SLOT(deleteLater()));
	connect(threadInputs, SIGNAL(finished()), threadInputs, SLOT(deleteLater()));

	// base connects for game logic
	connect(threadLogic, SIGNAL(started()), gameThread, SLOT(process()));
	connect(gameThread, SIGNAL(finished()), threadLogic, SLOT(quit()));
	connect(gameThread, SIGNAL(finished()), gameThread, SLOT(deleteLater()));
	connect(threadLogic, SIGNAL(finished()), threadLogic, SLOT(deleteLater()));
	connect(gameThread, SIGNAL(updateGameLogic()), gameScene, SLOT(eventTimeToMove())); // moves enemy, bullets, and check for collision
	//connect(inputThread, SIGNAL(finished()), gameScene, SLOT(advance()));
	// additionnal connects for inputs

	// additionnal connects for game logic
	
	connect(inputThread, SIGNAL(movePlayer()), gameScene, SLOT(eventTimePlayer()));
	// starting threads
	threadInputs->start();
	threadLogic->start();

	// show scene
	setScene(gameScene);
	this->ensureVisible(gameScene->gameRect);
	setBackgroundBrush(Qt::gray);
	setCacheMode(QGraphicsView::CacheBackground);
	setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
	show();
}

GameWindow::~GameWindow()
{
	// delete all dynamic objects
	delete inputThread;
	delete gameThread;
	delete threadInputs;
	delete threadLogic;
	delete gameScene;
}


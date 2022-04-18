#include "stackedw.h"

StackedW::StackedW()
{
	// init all pages
	mainMenu = new MainMenu();
	pauseMenu = new PauseMenu();
	gameWindow = new GameWindow();

	// adding all pages to the stacked widget
	addWidget(mainMenu);
	addWidget(gameWindow);
	addWidget(pauseMenu); 

	// setup the button fonctions for the main menu
	QObject::connect(mainMenu->goBtn, SIGNAL(clicked()), gameWindow->gameScene, SLOT(eventStart()));
	QObject::connect(mainMenu->goBtn, SIGNAL(clicked()), SLOT(goToGame()));
	QObject::connect(mainMenu->quitBtn, SIGNAL(clicked()), SLOT(closeWindow()));

	// setup the escape button to pause the game
	QObject::connect(gameWindow->gameScene, SIGNAL(pause()), SLOT(goToPause()));

	// setup the button fonctions for the pause menu
	QObject::connect(pauseMenu->resumeBtn, SIGNAL(clicked()), gameWindow->gameScene, SLOT(eventResume()));
	QObject::connect(pauseMenu->resumeBtn, SIGNAL(clicked()), SLOT(goToGame()));
	QObject::connect(pauseMenu->quitBtn, SIGNAL(clicked()), SLOT(closeWindow()));
	
	// Fix the size of the window and show the mainMenu
	setCurrentWidget(mainMenu);
	setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	show();
}

StackedW::~StackedW()
{
	delete mainMenu;
	delete gameWindow;
	delete pauseMenu;
}

/// <summary>
/// This slot changes the showed widget to be the game screen
/// </summary>
void StackedW::goToGame()
{
	setCurrentWidget(gameWindow);
}

/// <summary>
/// This slot changes the showed widget to be the pause menu
/// </summary>
void StackedW::goToPause()
{
	setCurrentWidget(pauseMenu);
}

/// <summary>
/// This slot stops the threads getting the game inputs and
/// running the game logic
/// </summary>
void StackedW::closeWindow()
{
	gameWindow->gameThread->stop = true;
	gameWindow->inputThread->stop = true;
	_sleep(200);
}
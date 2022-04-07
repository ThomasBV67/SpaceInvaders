#include "spaceinvaderwindow.h"
#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QStackedWidget>

SpaceInvaderWindow* game;

int main(int argc, char *argv[])
{
	//Init app
	QApplication a(argc, argv);

	QMainWindow window;

	QStackedWidget* sWidget = new QStackedWidget();

	QWidget* widget1 = new QWidget();
	QWidget* widget2 = new QWidget();

	sWidget->addWidget(widget1);
	sWidget->addWidget(widget2);

	sWidget->setCurrentWidget(widget1);

	//game = new SpaceInvaderWindow();
	/*
	//create scene for the items to be in
	QGraphicsScene* scene = new QGraphicsScene();
	QGraphicsScene* scene2 = new QGraphicsScene();


	//create player and set size to 100 by 100
	Player* player = new Player();
	Player* player2 = new Player();

	player->setRect(0, 0, 100, 100);
	player2->setRect(0, 0, 100, 200);

	// add player to scene
	scene->addItem(player);
	scene2->addItem(player2);

	// allow player to be focusable and respond to events
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	// create view item to show the scene on screen
	QGraphicsView* view = new QGraphicsView(scene);
	view->show();

	// set fixed sizes for the window
	view->setFixedSize(800,600);
	scene->setSceneRect(0,0,780,580);
	scene2->setSceneRect(0, 0, 780, 580);

	view->setScene(scene2);

	view->show();
	*/
	return a.exec();
}

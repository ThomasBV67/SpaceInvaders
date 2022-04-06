#include "spaceinvaderwindow.h"
#include "player.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
	//Init app
	QApplication a(argc, argv);

	//create scene for the items to be in
	QGraphicsScene* scene = new QGraphicsScene();

	//create player and set size to 100 by 100
	Player* player = new Player();
	player->setRect(0, 0, 100, 100);

	// add player to scene
	scene->addItem(player);

	// allow player to be focusable and respond to events
	player->setFlag(QGraphicsItem::ItemIsFocusable);
	player->setFocus();

	// create view item to show the scene on screen
	QGraphicsView* view = new QGraphicsView(scene);
	view->show();

	// set fixed sizes for the window
	view->setFixedSize(800,600);
	scene->setSceneRect(0,0,780,580);

	return a.exec();
}

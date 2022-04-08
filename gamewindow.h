#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "mainmenu.h"

class GameWindow : public QGraphicsView
{
    public:
        // Constructors
        GameWindow(QWidget* parent = NULL);

        // Public methods
        void start();

        // Public attributes
        MainMenu* mainMenu;

    private:
};
#endif // SPACEINVADERWINDOW_H

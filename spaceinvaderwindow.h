#ifndef SPACEINVADERWINDOW_H
#define SPACEINVADERWINDOW_H

#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "mainmenu.h"

class SpaceInvaderWindow : public QGraphicsView
{
    public:
        // Constructors
        SpaceInvaderWindow(QWidget* parent = NULL);

        // Public methods
        void start();

        // Public attributes
        MainMenu* mainMenu;

    private:
};
#endif // SPACEINVADERWINDOW_H

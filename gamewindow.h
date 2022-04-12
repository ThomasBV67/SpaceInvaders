#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtCore>

#include "mainmenu.h"
#include "gamescene.h"
#include "inputthread.h"


class GameWindow : public QGraphicsView
{
    public:
        // Constructors
        GameWindow(QWidget* parent = NULL);
        ~GameWindow();
        // Public methods
        void start();

        // Public attributes
        GameScene* gameScene;
        InputThread* inputThread;
        QThread* threadObj;

    private:
};
#endif // SPACEINVADERWINDOW_H

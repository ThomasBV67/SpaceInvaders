#pragma once
#pragma once
#ifndef GAMESPEEDTHREAD_H
#define GAMESPEEDTHREAD_H

#include "defines.h"

#include <QtCore>
#include <QDebug>

class GameSpeedThread : public QObject
{
    Q_OBJECT
public:
    GameSpeedThread() {};
    ~GameSpeedThread() {};

public slots:
    void process();
    void updateGameSpeed(int newSpeed) {};
    void killProcess() {};

signals:
    void finished();
    void moveAliens();
    void updateGameLogic();

private:
    int gameSpeed=100;
};
#endif
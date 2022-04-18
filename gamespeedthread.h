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

    bool stop = false;

public slots:
    void process();
    void updateGameSpeed(int);
    void killProcess() {};

signals:
    void finished();
    void moveAliens();
    void updateGameLogic();

private:
    int gameSpeed=33;
};
#endif
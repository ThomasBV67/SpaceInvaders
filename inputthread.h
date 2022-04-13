#pragma once
#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H

#include "defines.h"
#include "gamescene.h"

#include <QtCore>
#include <QDebug>

class InputThread : public QObject
{
    Q_OBJECT
public:
	InputThread();
    ~InputThread() {};

public slots:
    void process();
    void updateGameSpeed() {};

signals:
    void finished();
    void moveAliens();
    void error(QString err);

private:

};
#endif
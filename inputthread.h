#pragma once
#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H

#include "defines.h"
#include "gamescene.h"
#include "SerialPort.h"
#include "json.h"
#include "controller.h"

#include <iostream>
#include <string>

#include <QtCore>
#include <QDebug>

using namespace std;
using json = nlohmann::json;

class InputThread : public QObject
{
    Q_OBJECT
public:
	InputThread();
    ~InputThread() {};

    bool stop = false;
    Controller* controller;

public slots:
    void process();
    void updateGameSpeed() {};
    void updatedValues(DataController);

signals:
    void finished();
    void movePlayer(DataController);
    void controllerConnected();
    void error(QString err);

private:

};
#endif
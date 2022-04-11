#pragma once
#ifndef INPUTTHREAD_H
#define INPUTTHREAD_H

#include "defines.h"

#include <QtCore>
#include <QDebug>

class InputThread : public QThread
{
public:
	InputThread();
	void run();

private:

};
#endif
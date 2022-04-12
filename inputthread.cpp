#include "inputthread.h"

InputThread::InputThread()
{

}

void InputThread::run()
{
	int i = 0;

	while (!exit)
	{
		qDebug() << i;
		i++;
		sleep(1);
	}
}
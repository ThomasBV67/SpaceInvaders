#include "inputthread.h"

InputThread::InputThread()
{

}

void InputThread::run()
{
	int i = 0;

	while (1)
	{
		qDebug() << i;
		i++;
		sleep(1);
	}
}
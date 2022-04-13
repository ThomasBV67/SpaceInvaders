#include "inputthread.h"

InputThread::InputThread()
{

}

void InputThread::process()
{
	int i = 0;
	
	while (1)
	{
		emit movePlayer();
		_sleep(33);
	}
	emit finished();
}
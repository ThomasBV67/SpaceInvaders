#include "inputthread.h"

InputThread::InputThread()
{

}

void InputThread::process()
{
	int i = 0;
	
	/*while (1)
	{
		emit moveAliens();
		_sleep(1000);
	}*/
	emit finished();
}
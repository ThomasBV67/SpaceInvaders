#include "inputthread.h"

InputThread::InputThread()
{

}

/// <summary>
/// This is the main function used by the thread that deals with controller
/// input. This has not been fully implemented yet.
/// </summary>
void InputThread::process()
{
	while (!stop)
	{
		emit movePlayer();
		_sleep(33);
	}
	emit finished();
}
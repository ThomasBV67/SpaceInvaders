#include "gamespeedthread.h"

void GameSpeedThread::process()
{
	while (1)
	{
		emit moveAliens();
		_sleep(gameSpeed);
	}
	emit finished();
}
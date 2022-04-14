#include "gamespeedthread.h"

void GameSpeedThread::process()
{
	while (1)
	{
		emit updateGameLogic();
		_sleep(gameSpeed);
	}
	emit finished();
}
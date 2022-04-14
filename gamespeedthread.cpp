#include "gamespeedthread.h"

/// <summary>
/// This is the main function of the thread that deals with the game speed
/// </summary>
void GameSpeedThread::process()
{
	while (!stop)
	{
		emit updateGameLogic();
		_sleep(gameSpeed);
	}
	emit finished();
}
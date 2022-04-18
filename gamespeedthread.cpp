#include "gamespeedthread.h"

/// <summary>
/// This is the main function of the thread that deals with the game speed
/// </summary>
void GameSpeedThread::process()
{
	while (!stop)
	{
		emit updateGameLogic();
		QCoreApplication::processEvents();
		_sleep(gameSpeed);
	}
	emit finished();
}

void GameSpeedThread::updateGameSpeed(int newSpeed)
{
	gameSpeed = 100-newSpeed;
}
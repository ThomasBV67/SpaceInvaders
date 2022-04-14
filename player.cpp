#include "player.h"

Player::Player(QGraphicsScene* inparent)
{
	setPixmap(QPixmap(":/images/player.png"));
	speed = 0;
	setPos(100 + (X_RIGHT_LIMIT - X_LEFT_LIMIT) / 2, WINDOW_HEIGHT - BORDER_WIDTH_TOP - 50);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();
}

/// <summary>
/// 
/// </summary>
void Player::updatePlayer() {
	moveBy(speed, 0);
}

/// <summary>
/// 
/// </summary>
void Player::customAdvance() {
	qreal temp_X = x() + speed;

	if (temp_X <= X_LEFT_LIMIT) {
		temp_X = X_LEFT_LIMIT;
	}
	else if (temp_X + PLAYER_WIDTH >= X_RIGHT_LIMIT) {
		temp_X = X_RIGHT_LIMIT - PLAYER_WIDTH;
	}
	setPos(temp_X, y());
}

/// <summary>
/// 
/// </summary>
/// <param name="inGameRect"></param>
void Player::setGameRect(QGraphicsRectItem* inGameRect) {
	gameRect = inGameRect;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
Bullet* Player::shoot() {
	Bullet* bullet = new Bullet(true, this);
	return bullet;
}

/// <summary>
/// 
/// </summary>
/// <param name="event"></param>
void Player::keyPressEvent(QKeyEvent* event) {



}
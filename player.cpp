#include "player.h"

Player::Player(QGraphicsScene* inparent)
{
	setPixmap(QPixmap(":/images/player.png"));
	speed = 0;
	setPos(100 + (X_RIGHT_LIMIT - X_LEFT_LIMIT) / 2, WINDOW_HEIGHT - BORDER_WIDTH_TOP - 50);
	setFlag(QGraphicsItem::ItemIsFocusable);
	setFocus();
}

void Player::updatePlayer() {
	moveBy(speed, 0);
}
void Player::advance(int step) {
	if (!step)
		return;
	qreal temp_X = x() + speed;

	if (temp_X <= X_LEFT_LIMIT) {
		temp_X = X_LEFT_LIMIT;
	}
	else if (temp_X + PLAYER_WIDTH >= X_RIGHT_LIMIT) {
		temp_X = X_RIGHT_LIMIT - PLAYER_WIDTH;
	}
	setPos(temp_X, y());
}

void Player::setGameRect(QGraphicsRectItem* inGameRect) {
	gameRect = inGameRect;
}

Bullet* Player::shoot() {
	Bullet* bullet = new Bullet(true, this);
	return bullet;
}

void Player::keyPressEvent(QKeyEvent* event) {



}
#include "player.h"

Player::Player(QGraphicsScene* inparent)
{
	setPixmap(QPixmap(":/images/player.png"));
	speed = 0;
	bombs = 0;
	shields = PLAYER_SHIELDAMOUNT;
	hitPoints = PLAYER_HITPOINTS;
	shieldProtected = false;
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

void Player::useShield()
{
	if (shields > 0) {
		shields--;
		shieldProtected = true;
		setPixmap(QPixmap(":/images/playershield.png"));
	}
}

bool Player::getHit()
{
	if (shieldProtected) {
		shieldProtected = false;
		setPixmap(QPixmap(":/images/player.png"));
	}
	hitPoints--;
	if (hitPoints > 0)
		return true;
	else
		return false;
}
// true = dash a droite, false = dash a gauche
void Player::dash(bool sens)
{
	QTime currenttime = QTime::currentTime();
	int pastSpeed = speed;
	if (sens)
		speed = 50;
	else
		speed = -50;
	customAdvance();
	customAdvance();
	speed = pastSpeed;
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

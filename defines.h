#pragma once
#ifndef DEFINES_H
#define DEFINES_H

#define WINDOW_WIDTH	1024
#define WINDOW_HEIGHT	768

#define BORDER_WIDTH_TOP	50
#define BORDER_WIDTH_SIDE	100

#define PLAYER_WIDTH	36
#define PLAYER_HEIGHT	24
#define PLAYER_SHIELDAMOUNT 3
#define PLAYER_HITPOINTS 10
#define PLAYER_TYPE 65539


#define INVADER_WIDTH	44
#define INVADER_HEIGHT	32
#define INVADER_TYPE 65537

#define BULLET_WIDTH 2
#define BULLET_HEIGHT 8
#define BULLET_SPEED 10
#define BULLET_TYPE 65538

#define SHIELD_WIDTH 60
#define SHIELD_HEIGHT 32
#define SHIELD_BASEHP 5
#define SHIELD_TYPE 65540

#define SPECIAL_WIDTH 48
#define SPECIAL_HEIGHT 32
#define SPECIAL_TYPE 65541

#define GAMERECT_TYPE 3

#define START_BTN	0
#define QUIT_BTN	1

#define RIGHT	0
#define LEFT	1
#define DOWN	2

#define X_RIGHT_LIMIT	1000
#define X_LEFT_LIMIT	200

#define ENEMY_MOVE_INCREMENT	2
#define ENEMY_DOWN_INCREMENT	10

#define VERTICAL_SPREAD		50

#define BAUD 115200           // Frequence de transmission serielle
#define MSG_MAX_SIZE 1024   // Longueur maximale d'un message

#endif	
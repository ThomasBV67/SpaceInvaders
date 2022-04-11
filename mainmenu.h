#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include "defines.h"

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFont>
#include <QPalette>

class MainMenu : public QWidget
{
public:
	MainMenu(QWidget* parent = NULL);
	void startGame(); // TO DO
	void quitGame(); // TO DO
	void selectButton(int btn);

private:
	QVBoxLayout* mainLayout;
	QLabel* titleLabel;
	QPushButton* goBtn;
	QPushButton* quitBtn;
	int selectedBtn = START_BTN;
};
#endif
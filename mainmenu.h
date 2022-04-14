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

class MainMenu : public QWidget, public QObject
{
	Q_OBJECT
public:
	MainMenu(QWidget* parent = NULL);
	void startGame(); // TO DO
	void quitGame(); // TO DO
	void selectButton(int btn);
	QVBoxLayout* mainLayout;
	QPushButton* goBtn;
	QPushButton* quitBtn;
	int selectedBtn = START_BTN;

public slots:

signals: 
	void changeWindow();
	void killAll();
	
private:
	

};
#endif
#pragma once
#ifndef MAINMENU_H
#define MAINMENU_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPushButton>S
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFont>

class MainMenu : public QWidget
{
public:
	MainMenu();
	QVBoxLayout* mainLayout;
	QGroupBox* box;
	QLabel* titleLabel;
	QPushButton* goBtn;
	QPushButton* quitBtn;
private:
	
};
#endif
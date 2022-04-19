#pragma once
#include "defines.h"

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QFont>
#include <QPalette>

class GameOverMenu : public QWidget
{
	Q_OBJECT
public:
	GameOverMenu(QWidget* parent = NULL);
	~GameOverMenu();

	QVBoxLayout* mainLayout;
	QPushButton* restartBtn;
	QPushButton* quitBtn;
	QLabel* scoreLabel;
	int score = 0;

public slots:

signals:

private:

};
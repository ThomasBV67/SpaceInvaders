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

class PauseMenu : public QWidget
{
	Q_OBJECT
public:
	PauseMenu(QWidget* parent = NULL);
	~PauseMenu();

	QVBoxLayout* mainLayout;
	QPushButton* resumeBtn;
	QPushButton* quitBtn;
	QLabel* pauseLabel;

public slots:

signals:

private:

};
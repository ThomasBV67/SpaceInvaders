#include "mainmenu.h"

MainMenu::MainMenu()
{
	QFont font;
	font.setPixelSize(40);
	font.setWeight(QFont::Bold);

	goBtn = new QPushButton();
	goBtn->setFixedSize(300, 100);
	goBtn->setText("Start");
	goBtn->setFont(font);

	quitBtn = new QPushButton();
	quitBtn->setFixedSize(300, 100);
	quitBtn->setText("Quit");
	quitBtn->setFont(font);

	titleLabel = new QLabel();
	titleLabel->setText("Space Invaders");
	titleLabel->setFixedSize(300, 100);
	titleLabel->setFont(font);
	titleLabel->setAlignment(Qt::AlignCenter);

	QLabel* spacer = new QLabel();
	spacer->setFixedSize(300, 50);

	mainLayout = new QVBoxLayout();
	mainLayout->addWidget(titleLabel);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(goBtn);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(quitBtn);
	mainLayout->setAlignment(Qt::AlignCenter);

	setLayout(mainLayout);
}
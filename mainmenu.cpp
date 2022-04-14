#include "mainmenu.h"

MainMenu::MainMenu(QWidget* parent)
{
	// create a font object to apply a specific style to the text / buttons
	QFont font;
	font.setPixelSize(40);
	font.setWeight(QFont::Bold);

	setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// init of the start button
	goBtn = new QPushButton();
	goBtn->setFixedSize(300, 100);
	goBtn->setText("Start");
	goBtn->setFont(font);

	// init of the quit button
	quitBtn = new QPushButton();
	quitBtn->setFixedSize(300, 100);
	quitBtn->setText("Quit");
	quitBtn->setFont(font);

	// create a spacer objet to space the layout
	QLabel* spacer = new QLabel();
	spacer->setFixedSize(300, 50);

	// Add green accents to the start button
	QPalette pal = goBtn->palette();
	pal.setColor(QPalette::Button, QColor(Qt::darkGreen));
	pal.setColor(QPalette::ButtonText, QColor(Qt::darkGreen));
	goBtn->setAutoFillBackground(true);
	goBtn->setPalette(pal);

	// Add red accents to the quit button
	pal.setColor(QPalette::Button, QColor(Qt::red));
	pal.setColor(QPalette::ButtonText, QColor(Qt::red));
	quitBtn->setAutoFillBackground(true);
	quitBtn->setPalette(pal);

	// Setup the layout
	mainLayout = new QVBoxLayout();
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(goBtn);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(quitBtn);
	mainLayout->setAlignment(Qt::AlignCenter);

	// apply the layout
	setLayout(mainLayout);

	// set the background image
	setAutoFillBackground(true);
	QPixmap backgrnd(":/images/backgroundMainMenu.png");
	backgrnd = backgrnd.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(backgroundRole(),QBrush(backgrnd));
	this->setPalette(palette);
}

/// <summary>
/// This function changes the selected button, will be used when the menus can be controlled
/// using the controller designed by the team. 
/// </summary>
/// <param name="btn"></param>
void MainMenu::selectButton(int btn)
{
	if (btn == START_BTN)
	{
		QPalette pal = goBtn->palette();
		pal.setColor(QPalette::Button, QColor(Qt::green));
		pal.setColor(QPalette::ButtonText, QColor(Qt::green));
		goBtn->setAutoFillBackground(true);
		goBtn->setPalette(pal);

		pal.setColor(QPalette::Button, QColor(Qt::white));
		pal.setColor(QPalette::ButtonText, QColor(Qt::black));
		quitBtn->setAutoFillBackground(true);
		quitBtn->setPalette(pal);
	}
	else if (btn == QUIT_BTN)
	{
		QPalette pal = quitBtn->palette();
		pal.setColor(QPalette::Button, QColor(Qt::blue));
		pal.setColor(QPalette::ButtonText, QColor(Qt::blue));
		quitBtn->setAutoFillBackground(true);
		quitBtn->setPalette(pal);

		pal.setColor(QPalette::Button, QColor(Qt::white));
		pal.setColor(QPalette::ButtonText, QColor(Qt::black));
		goBtn->setAutoFillBackground(true);
		goBtn->setPalette(pal);
	}
}
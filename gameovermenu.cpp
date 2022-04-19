#include "gameovermenu.h"

GameOverMenu::GameOverMenu(QWidget* parent)
{
	// create a font object to apply a specific style to the text / buttons
	QFont font;
	font.setPixelSize(40);
	font.setWeight(QFont::Bold);

	setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// init of the start button
	restartBtn = new QPushButton();
	restartBtn->setFixedSize(300, 100);
	restartBtn->setText("Restart");
	restartBtn->setFont(font);

	// init of the quit button
	quitBtn = new QPushButton();
	quitBtn->setFixedSize(300, 100);
	quitBtn->setText("Quit");
	quitBtn->setFont(font);

	// init of the label
	font.setPixelSize(80);
	gameoverLabel = new QLabel();
	gameoverLabel->setText("GAME OVER");
	gameoverLabel->setFont(font);
	
	// init of the label
	font.setPixelSize(80);
	scoreLabel = new QLabel();
	scoreLabel->setText(QString::number(score));
	scoreLabel->setFont(font);
	

	// create a spacer objet to space the layout
	QLabel* spacer = new QLabel();
	spacer->setFixedSize(300, 50);

	// Add green accents to the resume button
	QPalette pal = restartBtn->palette();
	pal.setColor(QPalette::Button, QColor(Qt::darkGreen));
	pal.setColor(QPalette::ButtonText, QColor(Qt::darkGreen));
	restartBtn->setAutoFillBackground(true);
	restartBtn->setPalette(pal);

	// Add red accents to the quit button
	pal.setColor(QPalette::Button, QColor(Qt::red));
	pal.setColor(QPalette::ButtonText, QColor(Qt::red));
	quitBtn->setAutoFillBackground(true);
	quitBtn->setPalette(pal);

	// Set the label's text as white
	pal.setColor(foregroundRole(), QColor(Qt::white));
	gameoverLabel->setPalette(pal);
	scoreLabel->setPalette(pal);

	// setup the layout
	mainLayout = new QVBoxLayout();
	mainLayout->addWidget(gameoverLabel);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(scoreLabel);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(restartBtn);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(quitBtn);
	mainLayout->setAlignment(Qt::AlignCenter);

	// set background black
	setAutoFillBackground(true);
	QPalette palette;
	palette.setBrush(backgroundRole(), QBrush(Qt::black));
	this->setPalette(palette);

	// apply the layout
	setLayout(mainLayout);
}

GameOverMenu::~GameOverMenu()
{

}
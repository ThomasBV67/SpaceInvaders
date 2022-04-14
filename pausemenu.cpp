#include "pausemenu.h"

PauseMenu::PauseMenu(QWidget* parent)
{
	// create a font object to apply a specific style to the text / buttons
	QFont font;
	font.setPixelSize(40);
	font.setWeight(QFont::Bold);

	setFixedSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	// init of the start button
	resumeBtn = new QPushButton();
	resumeBtn->setFixedSize(300, 100);
	resumeBtn->setText("Resume");
	resumeBtn->setFont(font);

	// init of the quit button
	quitBtn = new QPushButton();
	quitBtn->setFixedSize(300, 100);
	quitBtn->setText("Quit");
	quitBtn->setFont(font);

	// init of the label
	font.setPixelSize(80);
	pauseLabel = new QLabel();
	pauseLabel->setText("PAUSED");
	pauseLabel->setFont(font);

	// create a spacer objet to space the layout
	QLabel* spacer = new QLabel();
	spacer->setFixedSize(300, 50);

	// Add green accents to the resume button
	QPalette pal = resumeBtn->palette();
	pal.setColor(QPalette::Button, QColor(Qt::darkGreen));
	pal.setColor(QPalette::ButtonText, QColor(Qt::darkGreen));
	resumeBtn->setAutoFillBackground(true);
	resumeBtn->setPalette(pal);

	// Add red accents to the quit button
	pal.setColor(QPalette::Button, QColor(Qt::red));
	pal.setColor(QPalette::ButtonText, QColor(Qt::red));
	quitBtn->setAutoFillBackground(true);
	quitBtn->setPalette(pal);

	// Set the label's text as white
	pal.setColor(foregroundRole(), QColor(Qt::white));
	pauseLabel->setPalette(pal);

	// setup the layout
	mainLayout = new QVBoxLayout();
	mainLayout->addWidget(pauseLabel);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(spacer);
	mainLayout->addWidget(resumeBtn);
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

PauseMenu::~PauseMenu()
{

}
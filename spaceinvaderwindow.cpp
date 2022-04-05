#include "spaceinvaderwindow.h"
#include "ui_spaceinvaderwindow.h"

SpaceInvaderWindow::SpaceInvaderWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SpaceInvaderWindow)
{
    ui->setupUi(this);
}

SpaceInvaderWindow::~SpaceInvaderWindow()
{
    delete ui;
}


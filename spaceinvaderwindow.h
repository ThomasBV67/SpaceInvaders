#ifndef SPACEINVADERWINDOW_H
#define SPACEINVADERWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SpaceInvaderWindow; }
QT_END_NAMESPACE

class SpaceInvaderWindow : public QMainWindow
{
    Q_OBJECT

public:
    SpaceInvaderWindow(QWidget *parent = nullptr);
    ~SpaceInvaderWindow();

private:
    Ui::SpaceInvaderWindow *ui;
};
#endif // SPACEINVADERWINDOW_H

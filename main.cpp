#include "spaceinvaderwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SpaceInvaderWindow window;
    window.show();
    return a.exec();
}

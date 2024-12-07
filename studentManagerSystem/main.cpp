#include "studentmanagersys.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentManagerSys w;
    w.showLogin();
    return a.exec();
}

#include "studentmanagersys.h"
#include "ui_studentmanagersys.h"

StudentManagerSys::StudentManagerSys(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentManagerSys)
{
    ui->setupUi(this);
}

StudentManagerSys::~StudentManagerSys()
{
    delete ui;
}


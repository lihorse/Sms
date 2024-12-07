#include "studentmanagersys.h"
#include "ui_studentmanagersys.h"
#include <QMessageBox>
StudentManagerSys::StudentManagerSys(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentManagerSys)
{
    ui->setupUi(this);
    login_t = new login;
    connect(login_t,SIGNAL(siglogincheck(const QString &, const QString &)),this,SLOT(onlogincheck(const QString &,const QString &)));
}

StudentManagerSys::~StudentManagerSys()
{
    delete ui;
}

void StudentManagerSys::showLogin()
{
    login_t->show();
}

void StudentManagerSys::onlogincheck(const QString &username, const QString &password)
{
    if(username == "123" && password == "123"){
        QMessageBox::warning(nullptr, "info", "登陆成功");
    }
    else{
         QMessageBox::warning(nullptr, "info", "失败");
    }
}


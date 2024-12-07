#include "login.h"
#include "ui_login.h"
#include <QDebug>

login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

}

login::~login()
{
    delete ui;
}

void login::loginInputClear()
{
    ui->username->clear();
    ui->password->clear();
}

void login::on_btn_log_clicked()
{
    QString usrname = ui->username->text();
    QString passwd = ui->password->text();
    if(ui->manager_check->isChecked())
    {
        emit siglogincheck(usrname,passwd,1);
        qDebug("选择");
    }
    else
    {
        emit siglogincheck(usrname,passwd,2);
        qDebug("未选择");
    }


}

void login::on_btn_clr_clicked()
{
    this->loginInputClear();
}

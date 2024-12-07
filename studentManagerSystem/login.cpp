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

void login::on_pushButton_clicked()
{
    bool ret = false;
    emit siglogincheck("123","123");

    if(ret)
    {
        qDebug()<<ret;
    }
}

#include "studentmanagersys.h"
#include "ui_studentmanagersys.h"
#include "flatui.h"
#include "qdebug.h"
#include "qdesktopwidget.h"
#include "qdatetime.h"
#include <QMessageBox>
#include <QList>
StudentManagerSys::StudentManagerSys(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentManagerSys)
{
    ui->setupUi(this);

    login_t = new login;
    connect(login_t,SIGNAL(siglogincheck(const QString &, const QString &,const int &)),this,SLOT(onlogincheck(const QString &,const QString &,const int &)));
    if(db_name.isEmpty())
    {
        db_name = "test";
        user_name = "root";
        user_passwd = "123456";
        db_server_ip = "127.0.0.1";
        db_server_port = 3306;
    }
    this->dataBaseInit();
    this->InitForm();
}

StudentManagerSys::~StudentManagerSys()
{
    delete ui;
}

void StudentManagerSys::showLogin()
{
    login_t->show();
}

void StudentManagerSys::dataBaseInit()
{
    db = new MysqlDBO(db_name);
    //    db->Disconnect();
    if(!db->Connect(user_name,user_passwd,db_server_ip,db_server_port))
    {
        qDebug("数据库连接失败");
    }
    else
    {
        qDebug("数据库连接成功");
    }
}

void StudentManagerSys::InitForm()
{
    this->menuBtnInit(userLevel);
    this->studentViewInit(userLevel);
    this->studentInfoShow();
}

void StudentManagerSys::menuBtnInit(int level)
{
    FlatUI::Instance()->setPushButtonQss(ui->btn1, 0, 0, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->btn2, 0, 0, "#1ABC9C", "#E6F8F5", "#2EE1C1", "#FFFFFF", "#16A086", "#A7EEE6");
    FlatUI::Instance()->setPushButtonQss(ui->btn3, 0, 0, "#3498DB", "#FFFFFF", "#5DACE4", "#E5FEFF", "#2483C7", "#A0DAFB");
    FlatUI::Instance()->setPushButtonQss(ui->btn4, 0, 0, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");
    //FlatUI::Instance()->setPushButtonQss(ui->btn5, 0, 0, "#E74C3C", "#FFFFFF", "#EC7064", "#FFF5E7", "#DC2D1A", "#F5A996");

    if(level == 2)
    {
        ui->btn5->setDisabled(true);
    }
}

void StudentManagerSys::studentViewInit(int level)
{
    //设置列数和列宽
    int width = qApp->desktop()->availableGeometry().width() - 120;
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnWidth(0, width * 0.06);
    ui->tableWidget->setColumnWidth(1, width * 0.10);
    ui->tableWidget->setColumnWidth(2, width * 0.06);
    ui->tableWidget->setColumnWidth(3, width * 0.10);
    ui->tableWidget->setColumnWidth(4, width * 0.20);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "设备编号" << "设备名称" << "设备地址" << "告警内容" << "告警时间";
    ui->tableWidget->setHorizontalHeaderLabels(headText);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //设置行高
    ui->tableWidget->setRowCount(300);
}

void StudentManagerSys::studentInfoShow()
{
    this->getStudentDataFromDB();
    for (int i = 0; i < 300; i++) {
        ui->tableWidget->setRowHeight(i, 24);

        QTableWidgetItem *itemDeviceID = new QTableWidgetItem(QString::number(i + 1));
        QTableWidgetItem *itemDeviceName = new QTableWidgetItem(QString("测试设备%1").arg(i + 1));
        QTableWidgetItem *itemDeviceAddr = new QTableWidgetItem(QString::number(i + 1));
        QTableWidgetItem *itemContent = new QTableWidgetItem("防区告警");
        QTableWidgetItem *itemTime = new QTableWidgetItem(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));

        ui->tableWidget->setItem(i, 0, itemDeviceID);
        ui->tableWidget->setItem(i, 1, itemDeviceName);
        ui->tableWidget->setItem(i, 2, itemDeviceAddr);
        ui->tableWidget->setItem(i, 3, itemContent);
        ui->tableWidget->setItem(i, 4, itemTime);
    }
}

void StudentManagerSys::getStudentDataFromDB()
{
   int ret =  db->GetFieldSize("user");

   qDebug()<<"GetFildSize:"<<ret;



}

void StudentManagerSys::onlogincheck(const QString &username, const QString &password,const int &level)
{
    int ret;
    QString msg;
    ret = db->FindCount("user",QString("WHERE username = '%1' AND password = '%2' AND level='%3';").arg(username).arg(password).arg(level));
    switch (level) {
    case 1: msg = "管理员用户";break;
    case 2: msg="普通用户";break;
    default:
        msg = "普通用户";
        break;
    }

    if(ret > 0){
        QMessageBox::warning(nullptr, "info", QString("%1登陆成功").arg(msg));
        login_t->hide();
        this->show();
    }
    else{
        QMessageBox::warning(nullptr, "info", QString("%1登录失败").arg(msg));
        login_t->loginInputClear();
    }
}


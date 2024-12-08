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
    this->classViewInit(userLevel);

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
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setColumnWidth(0, width * 0.06);
    ui->tableWidget->setColumnWidth(1, width * 0.10);
    ui->tableWidget->setColumnWidth(2, width * 0.06);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "学号" << "姓名" << "性别";
    ui->tableWidget->setHorizontalHeaderLabels(headText);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    //设置行高
    ui->tableWidget->setRowCount(300);
    this->studentInfoShow();
}

void StudentManagerSys::studentInfoShow()
{
    QList<QVariantList> list;
    list = this->getStudentDataFromDB();
    int i = 0;
    ui->tableWidget->clearContents();
    for(auto item:list)
    {
        ui->tableWidget->setRowHeight(i, 24);

        QTableWidgetItem *studentId = new QTableWidgetItem(item.at(0).toString());
        QTableWidgetItem *studentName = new QTableWidgetItem(item.at(1).toString());
        QTableWidgetItem *studentSex = new QTableWidgetItem(item.at(2).toString());

        ui->tableWidget->setItem(i, 0, studentId);
        ui->tableWidget->setItem(i, 1, studentName);
        ui->tableWidget->setItem(i, 2, studentSex);
        i++;
    }
}

QList<QVariantList> StudentManagerSys::getStudentDataFromDB()
{
    return db->GetDatas("student","*",NULL);
}

bool StudentManagerSys::findStudentInfoFromDB(int studentId, QString studentName, QString studentSex)
{
    QString sql;
    int ret;
    sql = QString("WHERE id='%1';").arg(studentId);

    ret = db->FindCount("student",sql);

    if(ret <= 0)
    {
        return false;
    }

    return true;
}

bool StudentManagerSys::deleteStudentInfoToDB(int studentId, QString studentName, QString studentSex)
{
    /*先查找此人存在*/
    if(!this->findStudentInfoFromDB(ui->lEdit_StudentId->text().toInt(),NULL,NULL))
    {
        qDebug("学生不存在");
        return false;
    }
    qDebug()<<"删除";
    db->DeleteData("student",QString("WHERE id='%1';").arg(studentId));
    return true;
}

bool StudentManagerSys::updateStudentInfoToDB(int studentId, QString studentName, QString studentSex)
{
    QStringList     qslist;
    QVariantList    qvlist;
    QString         strwhere;
    if(studentId < 0 || studentName.isEmpty() || studentSex.isEmpty())
    {
        qDebug("学生信息全都不许为空");
        return false;
    }
    /*先查找此人存在*/
    if(!this->findStudentInfoFromDB(ui->lEdit_StudentId->text().toInt(),NULL,NULL))
    {
        qDebug("学生不存在");
        return false;
    }

    qslist.append("id");
    qslist.append("name");
    qslist.append("sex");

    qvlist.append(QString::number(studentId));
    qvlist.append(studentName);
    qvlist.append(studentSex);

    strwhere = QString("WHERE id='%1';").arg(studentId);
    db->UpdateData("student",qslist,qvlist,strwhere);
    return true;
}

bool StudentManagerSys::addStudentInfoToDB(int studentId, QString studentName, QString studentSex)
{
    QStringList     qslist;
    QVariantList    qvlist;

    if(studentId < 0 || studentName.isEmpty() || studentSex.isEmpty())
    {
        qDebug("学生信息全都不许为空");
        return false;
    }
    /*先查找此人存在*/
    if(this->findStudentInfoFromDB(ui->lEdit_StudentId->text().toInt(),NULL,NULL))
    {
        qDebug("学生已经存在");
        return false;
    }
    qslist.append("id");
    qslist.append("name");
    qslist.append("sex");

    qvlist.append(QString::number(studentId));
    qvlist.append(studentName);
    qvlist.append(studentSex);

    db->AppendDataCustom("student",qslist,qvlist);
    return true;
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


void StudentManagerSys::on_btn1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void StudentManagerSys::on_btn2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void StudentManagerSys::on_btn3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void StudentManagerSys::on_btn4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void StudentManagerSys::on_btn5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void StudentManagerSys::on_pushButton_clicked()/*查询学生信息*/
{
    if(!this->findStudentInfoFromDB(ui->lEdit_StudentId->text().toInt(),ui->lEdit_StudentName->text(),ui->comboBox->currentText()))
    {
        QMessageBox::warning(this,"info","没有这个学生");
    }
    else
    {
        QMessageBox::warning(this,"info","有这个学生");
    }
}

void StudentManagerSys::on_pushButton_3_clicked()/*添加学生信息*/
{
    if(!this->addStudentInfoToDB(ui->lEdit_StudentId->text().toInt(),ui->lEdit_StudentName->text(),ui->comboBox->currentText()))
    {
        QMessageBox::warning(this,"info","学生信息添加失败");
        return;
    }

    this->studentInfoShow();
}

void StudentManagerSys::on_pushButton_2_clicked()/*修改学生信息*/
{
    if(!this->updateStudentInfoToDB(ui->lEdit_StudentId->text().toInt(),ui->lEdit_StudentName->text(),ui->comboBox->currentText()))
    {
        QMessageBox::warning(this,"info","学生信息修改失败");
        return;
    }

    this->studentInfoShow();
}

void StudentManagerSys::on_pushButton_4_clicked()/*删除学生信息*/
{
    if(!this->deleteStudentInfoToDB(ui->lEdit_StudentId->text().toInt(),ui->lEdit_StudentName->text(),ui->comboBox->currentText()))
    {
        QMessageBox::warning(this,"info","学生信息删除失败");
        return;
    }

    this->studentInfoShow();
}

void StudentManagerSys::classViewInit(int level)
{
    //设置列数和列宽
    int width = qApp->desktop()->availableGeometry().width() - 120;
    ui->classTbWidget->setColumnCount(3);
    ui->classTbWidget->setColumnWidth(0, width * 0.06);
    ui->classTbWidget->setColumnWidth(1, width * 0.10);
    ui->classTbWidget->setColumnWidth(2, width * 0.06);
    ui->classTbWidget->verticalHeader()->setDefaultSectionSize(25);

    QStringList headText;
    headText << "课程号" << "课程名" << "老师姓名";
    ui->classTbWidget->setHorizontalHeaderLabels(headText);
    ui->classTbWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->classTbWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->classTbWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->classTbWidget->setAlternatingRowColors(true);
    ui->classTbWidget->verticalHeader()->setVisible(false);
    ui->classTbWidget->horizontalHeader()->setStretchLastSection(true);

    //设置行高
    ui->classTbWidget->setRowCount(300);
    this->classInfoShow();
}

void StudentManagerSys::classInfoShow()
{
    QList<QVariantList> list;
    list = this->getClassDataFromDB();
    int i = 0;
    ui->classTbWidget->clearContents();
    for(auto item:list)
    {
        ui->classTbWidget->setRowHeight(i, 24);

        QTableWidgetItem *classID = new QTableWidgetItem(item.at(0).toString());
        QTableWidgetItem *className = new QTableWidgetItem(item.at(1).toString());
        QTableWidgetItem *teacher = new QTableWidgetItem(item.at(2).toString());

        ui->classTbWidget->setItem(i, 0, classID);
        ui->classTbWidget->setItem(i, 1, className);
        ui->classTbWidget->setItem(i, 2, teacher);
        i++;
    }
}

QList<QVariantList> StudentManagerSys::getClassDataFromDB()
{
    return db->GetDatas("class","*",NULL);
}

bool StudentManagerSys::findClassInfoFromDB(int classID, QString className, QString teacherName)
{
    QString sql;
    int ret;
    sql = QString("WHERE id='%1';").arg(classID);

    ret = db->FindCount("class",sql);

    if(ret <= 0)
    {
        return false;
    }

    return true;
}

bool StudentManagerSys::deleteClassInfoToDB(int classID, QString className, QString teacherName)
{
    /*先查找此人存在*/
       if(!this->findClassInfoFromDB(ui->lEditClassID->text().toInt(),NULL,NULL))
       {
           qDebug("学生不存在");
           return false;
       }
       qDebug()<<"删除";
       db->DeleteData("class",QString("WHERE id='%1';").arg(classID));
       return true;
}

bool StudentManagerSys::updateClassInfoToDB(int classID, QString className, QString teacherName)
{
    QStringList     qslist;
    QVariantList    qvlist;
    QString         strwhere;
    if(classID < 0 || className.isEmpty() || teacherName.isEmpty())
    {
        qDebug("课程信息全部不能为空");
        return false;
    }
    /*先查找此人存在*/
    if(!this->findClassInfoFromDB(ui->lEditClassID->text().toInt(),NULL,NULL))
    {
        qDebug("课程不存在");
        return false;
    }

    qslist.append("id");
    qslist.append("name");
    qslist.append("teacher");

    qvlist.append(QString::number(classID));
    qvlist.append(className);
    qvlist.append(teacherName);

    strwhere = QString("WHERE id='%1';").arg(classID);
    db->UpdateData("class",qslist,qvlist,strwhere);
    return true;
}

bool StudentManagerSys::addClassInfoToDB(int classID, QString className, QString teacherName)
{
    QStringList     qslist;
    QVariantList    qvlist;

    if(classID < 0 || className.isEmpty() || teacherName.isEmpty())
    {
        qDebug("学生信息全都不许为空");
        return false;
    }
    /*先查找此人存在*/
    if(this->findClassInfoFromDB(ui->lEditClassID->text().toInt(),NULL,NULL))
    {
        qDebug("课程信息已经存在");
        return false;
    }
    qslist.append("id");
    qslist.append("name");
    qslist.append("teacher");

    qvlist.append(QString::number(classID));
    qvlist.append(className);
    qvlist.append(teacherName);

    db->AppendDataCustom("class",qslist,qvlist);
    return true;
}

void StudentManagerSys::on_btnClassAdd_clicked()
{
    if(!this->addClassInfoToDB(ui->lEditClassID->text().toInt(),ui->lEditClassName->text(),ui->lEditTeacher->text()))
    {
        QMessageBox::warning(this,"info","课程信息添加失败");
        return;
    }

    this->classInfoShow();

}

void StudentManagerSys::on_btnClassDel_clicked()
{
    if(!this->deleteClassInfoToDB(ui->lEditClassID->text().toInt(),ui->lEditClassName->text(),ui->lEditTeacher->text()))
    {
        QMessageBox::warning(this,"info","学生信息删除失败");
        return;
    }

    this->classInfoShow();
}

void StudentManagerSys::on_btnClassUpdate_clicked()
{
    if(!this->updateClassInfoToDB(ui->lEditClassID->text().toInt(),ui->lEditClassName->text(),ui->lEditTeacher->text()))
    {
        QMessageBox::warning(this,"info","学生信息修改失败");
        return;
    }

    this->classInfoShow();
}

void StudentManagerSys::on_btnClassGet_clicked()
{
    if(!this->findClassInfoFromDB(ui->lEditClassID->text().toInt(),ui->lEditClassName->text(),ui->lEditTeacher->text()))
    {
        QMessageBox::warning(this,"info","没有这个课程");
    }
    else
    {
        QMessageBox::warning(this,"info","有这个课程");
    }
}

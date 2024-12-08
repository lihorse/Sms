#ifndef STUDENTMANAGERSYS_H
#define STUDENTMANAGERSYS_H

#include <QMainWindow>
#include "login.h"
#include "MysqlDBO.h"
QT_BEGIN_NAMESPACE
namespace Ui { class StudentManagerSys; }
QT_END_NAMESPACE

class StudentManagerSys : public QMainWindow
{
    Q_OBJECT

public:
    StudentManagerSys(QWidget *parent = nullptr);
    ~StudentManagerSys();
    void showLogin();
    void dataBaseInit();
    void InitForm();
    void menuBtnInit(int level);
    void studentViewInit(int level);
    void studentInfoShow();
    QList<QVariantList> getStudentDataFromDB();
    bool findStudentInfoFromDB(int studentId, QString studentName, QString studentSex);
    bool deleteStudentInfoToDB(int studentId, QString studentName, QString studentSex);
    bool updateStudentInfoToDB(int studentId, QString studentName, QString studentSex);
    bool addStudentInfoToDB(int studentId, QString studentName, QString studentSex);
private slots:
    void onlogincheck(const QString &username,const QString &password,const int &level);

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::StudentManagerSys *ui;

    login *login_t;
    DBOBase *db;

    int userLevel = 2;

    QString db_name;
    QString table_name;
    QString user_name;
    QString user_passwd;
    QString db_server_ip;
    int db_server_port;
};
#endif // STUDENTMANAGERSYS_H

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
    enum userLevel
    {
        administrator = 1,
        commonuser
    };

    enum findGradeMode
    {
      totalMode = 0,
      studentIDMode,
      studentNameMode,
      classNameMode,
      dateMode
    };
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


    void classViewInit(int level);
    void classInfoShow();
    QList<QVariantList> getClassDataFromDB();
    bool findClassInfoFromDB(int classID, QString className, QString teacherName);
    bool findClassInfoFromDB(QString className);
    bool deleteClassInfoToDB(int classID, QString className, QString teacherName);
    bool updateClassInfoToDB(int classID, QString className, QString teacherName);
    bool addClassInfoToDB(int classID, QString className, QString teacherName);

    void gradeViewInit(int level);
    void gradeInfoShow(QList<QVariantList> list);
    QList<QVariantList> getGradeDataFromDB(enum findGradeMode,int studentID, QString studentName, QString className, QString date);
    QList<QVariantList> getGradeDataFromDB();
    bool findGradeInfoFromDB(int studentID, QString studentName, QString className, QString date, double grade);
    bool findGradeInfoFromDB(int studentID, QString studentName, QString className);
    bool deleteGradeInfoToDB(int studentID, QString studentName, QString className, QString date, double grade);
    bool updateGradeInfoToDB(int studentID, QString studentName, QString className, QString date, double grade);
    bool addGradeInfoToDB(int studentID, QString studentName, QString className, QString date, double grade);


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

    void on_btnClassAdd_clicked();

    void on_btnClassDel_clicked();

    void on_btnClassUpdate_clicked();

    void on_btnClassGet_clicked();

    void on_btnGradeGet_clicked();

    void on_btnGradeUpdate_clicked();

    void on_btnGradeAdd_clicked();

    void on_btnGradeDel_clicked();

private:
    Ui::StudentManagerSys *ui;

    login *login_t;
    DBOBase *db;

    int userlevel = 1;

    QString db_name;
    QString table_name;
    QString user_name;
    QString user_passwd;
    QString db_server_ip;
    int db_server_port;
};
#endif // STUDENTMANAGERSYS_H

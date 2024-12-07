#ifndef STUDENTMANAGERSYS_H
#define STUDENTMANAGERSYS_H

#include <QMainWindow>
#include "login.h"
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
private slots:
    void onlogincheck(const QString &username,const QString &password);
private:
    Ui::StudentManagerSys *ui;

    login *login_t;
};
#endif // STUDENTMANAGERSYS_H

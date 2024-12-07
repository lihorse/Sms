#ifndef STUDENTMANAGERSYS_H
#define STUDENTMANAGERSYS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentManagerSys; }
QT_END_NAMESPACE

class StudentManagerSys : public QMainWindow
{
    Q_OBJECT

public:
    StudentManagerSys(QWidget *parent = nullptr);
    ~StudentManagerSys();

private:
    Ui::StudentManagerSys *ui;
};
#endif // STUDENTMANAGERSYS_H

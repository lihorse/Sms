/********************************************************************************
** Form generated from reading UI file 'studentmanagersys.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTMANAGERSYS_H
#define UI_STUDENTMANAGERSYS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentManagerSys
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentManagerSys)
    {
        if (StudentManagerSys->objectName().isEmpty())
            StudentManagerSys->setObjectName(QString::fromUtf8("StudentManagerSys"));
        StudentManagerSys->resize(800, 600);
        centralwidget = new QWidget(StudentManagerSys);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        StudentManagerSys->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StudentManagerSys);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        StudentManagerSys->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentManagerSys);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StudentManagerSys->setStatusBar(statusbar);

        retranslateUi(StudentManagerSys);

        QMetaObject::connectSlotsByName(StudentManagerSys);
    } // setupUi

    void retranslateUi(QMainWindow *StudentManagerSys)
    {
        StudentManagerSys->setWindowTitle(QCoreApplication::translate("StudentManagerSys", "StudentManagerSys", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentManagerSys: public Ui_StudentManagerSys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMANAGERSYS_H

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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentManagerSys
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QTableWidget *tableWidget;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *page_5;
    QWidget *page_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn1;
    QPushButton *btn2;
    QPushButton *btn3;
    QPushButton *btn4;
    QPushButton *btn5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StudentManagerSys)
    {
        if (StudentManagerSys->objectName().isEmpty())
            StudentManagerSys->setObjectName(QString::fromUtf8("StudentManagerSys"));
        StudentManagerSys->resize(800, 600);
        StudentManagerSys->setMinimumSize(QSize(800, 600));
        StudentManagerSys->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(StudentManagerSys);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 30, 800, 600));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        tableWidget = new QTableWidget(page_1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 40, 651, 241));
        stackedWidget->addWidget(page_1);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 2, 666, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn1 = new QPushButton(widget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setMinimumSize(QSize(128, 23));
        btn1->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn1);

        btn2 = new QPushButton(widget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setMinimumSize(QSize(128, 23));
        btn2->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn2);

        btn3 = new QPushButton(widget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setMinimumSize(QSize(128, 23));
        btn3->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn3);

        btn4 = new QPushButton(widget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setMinimumSize(QSize(128, 23));
        btn4->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn4);

        btn5 = new QPushButton(widget);
        btn5->setObjectName(QString::fromUtf8("btn5"));
        btn5->setMinimumSize(QSize(128, 23));
        btn5->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn5);

        StudentManagerSys->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StudentManagerSys);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        StudentManagerSys->setMenuBar(menubar);
        statusbar = new QStatusBar(StudentManagerSys);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        StudentManagerSys->setStatusBar(statusbar);

        retranslateUi(StudentManagerSys);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StudentManagerSys);
    } // setupUi

    void retranslateUi(QMainWindow *StudentManagerSys)
    {
        StudentManagerSys->setWindowTitle(QCoreApplication::translate("StudentManagerSys", "StudentManagerSys", nullptr));
        btn1->setText(QCoreApplication::translate("StudentManagerSys", "\345\255\246\347\224\237\344\277\241\346\201\257", nullptr));
        btn2->setText(QCoreApplication::translate("StudentManagerSys", "\350\257\276\347\250\213\344\277\241\346\201\257", nullptr));
        btn3->setText(QCoreApplication::translate("StudentManagerSys", "\346\210\220\347\273\251\346\237\245\350\257\242", nullptr));
        btn4->setText(QCoreApplication::translate("StudentManagerSys", "\346\210\220\347\273\251\347\273\237\350\256\241", nullptr));
        btn5->setText(QCoreApplication::translate("StudentManagerSys", "\347\224\250\346\210\267\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentManagerSys: public Ui_StudentManagerSys {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTMANAGERSYS_H

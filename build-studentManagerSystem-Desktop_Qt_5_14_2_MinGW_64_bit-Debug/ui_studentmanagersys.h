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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
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
    QLineEdit *lEdit_StudentId;
    QLineEdit *lEdit_StudentName;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QComboBox *comboBox;
    QWidget *page_3;
    QTableWidget *classTbWidget;
    QPushButton *btnClassUpdate;
    QPushButton *btnClassAdd;
    QPushButton *btnClassDel;
    QLineEdit *lEditTeacher;
    QLineEdit *lEditClassName;
    QPushButton *btnClassGet;
    QLineEdit *lEditClassID;
    QWidget *page_4;
    QTableWidget *tableWidget_4;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_9;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lineEdit_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QWidget *page_5;
    QWidget *page_2;
    QTableWidget *tableWidget_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *layoutWidget;
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
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        tableWidget = new QTableWidget(page_1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(449, 70, 351, 400));
        lEdit_StudentId = new QLineEdit(page_1);
        lEdit_StudentId->setObjectName(QString::fromUtf8("lEdit_StudentId"));
        lEdit_StudentId->setGeometry(QRect(20, 70, 113, 20));
        lEdit_StudentName = new QLineEdit(page_1);
        lEdit_StudentName->setObjectName(QString::fromUtf8("lEdit_StudentName"));
        lEdit_StudentName->setGeometry(QRect(140, 70, 113, 20));
        pushButton = new QPushButton(page_1);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 150, 75, 23));
        pushButton_2 = new QPushButton(page_1);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 150, 75, 23));
        pushButton_3 = new QPushButton(page_1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(50, 220, 75, 23));
        pushButton_4 = new QPushButton(page_1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(180, 220, 75, 23));
        comboBox = new QComboBox(page_1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(270, 70, 69, 22));
        stackedWidget->addWidget(page_1);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        classTbWidget = new QTableWidget(page_3);
        classTbWidget->setObjectName(QString::fromUtf8("classTbWidget"));
        classTbWidget->setGeometry(QRect(390, 20, 341, 251));
        btnClassUpdate = new QPushButton(page_3);
        btnClassUpdate->setObjectName(QString::fromUtf8("btnClassUpdate"));
        btnClassUpdate->setGeometry(QRect(30, 170, 75, 23));
        btnClassAdd = new QPushButton(page_3);
        btnClassAdd->setObjectName(QString::fromUtf8("btnClassAdd"));
        btnClassAdd->setGeometry(QRect(30, 110, 75, 23));
        btnClassDel = new QPushButton(page_3);
        btnClassDel->setObjectName(QString::fromUtf8("btnClassDel"));
        btnClassDel->setGeometry(QRect(200, 110, 75, 23));
        lEditTeacher = new QLineEdit(page_3);
        lEditTeacher->setObjectName(QString::fromUtf8("lEditTeacher"));
        lEditTeacher->setGeometry(QRect(260, 50, 113, 20));
        lEditClassName = new QLineEdit(page_3);
        lEditClassName->setObjectName(QString::fromUtf8("lEditClassName"));
        lEditClassName->setGeometry(QRect(140, 50, 113, 20));
        btnClassGet = new QPushButton(page_3);
        btnClassGet->setObjectName(QString::fromUtf8("btnClassGet"));
        btnClassGet->setGeometry(QRect(200, 170, 75, 23));
        lEditClassID = new QLineEdit(page_3);
        lEditClassID->setObjectName(QString::fromUtf8("lEditClassID"));
        lEditClassID->setGeometry(QRect(20, 50, 113, 20));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        tableWidget_4 = new QTableWidget(page_4);
        tableWidget_4->setObjectName(QString::fromUtf8("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(10, 90, 691, 331));
        lineEdit_7 = new QLineEdit(page_4);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(30, 30, 113, 20));
        lineEdit_8 = new QLineEdit(page_4);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(160, 30, 113, 20));
        lineEdit_9 = new QLineEdit(page_4);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(280, 30, 113, 20));
        dateTimeEdit = new QDateTimeEdit(page_4);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(410, 30, 161, 22));
        lineEdit_10 = new QLineEdit(page_4);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));
        lineEdit_10->setGeometry(QRect(580, 30, 113, 20));
        pushButton_13 = new QPushButton(page_4);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(30, 60, 75, 23));
        pushButton_14 = new QPushButton(page_4);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(120, 60, 75, 23));
        pushButton_15 = new QPushButton(page_4);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));
        pushButton_15->setGeometry(QRect(210, 60, 75, 23));
        pushButton_16 = new QPushButton(page_4);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));
        pushButton_16->setGeometry(QRect(310, 60, 75, 23));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        tableWidget_2 = new QTableWidget(page_2);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(400, 40, 341, 251));
        lineEdit = new QLineEdit(page_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 70, 113, 20));
        lineEdit_2 = new QLineEdit(page_2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(160, 70, 113, 20));
        lineEdit_3 = new QLineEdit(page_2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(280, 70, 113, 20));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 130, 75, 23));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(210, 130, 75, 23));
        pushButton_7 = new QPushButton(page_2);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(40, 190, 75, 23));
        pushButton_8 = new QPushButton(page_2);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(210, 190, 75, 23));
        stackedWidget->addWidget(page_2);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 2, 666, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn1 = new QPushButton(layoutWidget);
        btn1->setObjectName(QString::fromUtf8("btn1"));
        btn1->setMinimumSize(QSize(128, 23));
        btn1->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn1);

        btn2 = new QPushButton(layoutWidget);
        btn2->setObjectName(QString::fromUtf8("btn2"));
        btn2->setMinimumSize(QSize(128, 23));
        btn2->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn2);

        btn3 = new QPushButton(layoutWidget);
        btn3->setObjectName(QString::fromUtf8("btn3"));
        btn3->setMinimumSize(QSize(128, 23));
        btn3->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn3);

        btn4 = new QPushButton(layoutWidget);
        btn4->setObjectName(QString::fromUtf8("btn4"));
        btn4->setMinimumSize(QSize(128, 23));
        btn4->setMaximumSize(QSize(128, 23));

        horizontalLayout->addWidget(btn4);

        btn5 = new QPushButton(layoutWidget);
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

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(StudentManagerSys);
    } // setupUi

    void retranslateUi(QMainWindow *StudentManagerSys)
    {
        StudentManagerSys->setWindowTitle(QCoreApplication::translate("StudentManagerSys", "StudentManagerSys", nullptr));
        lEdit_StudentId->setInputMask(QString());
        lEdit_StudentId->setText(QString());
        lEdit_StudentId->setPlaceholderText(QCoreApplication::translate("StudentManagerSys", "\345\255\246\345\217\267", nullptr));
        lEdit_StudentName->setPlaceholderText(QCoreApplication::translate("StudentManagerSys", "\345\247\223\345\220\215", nullptr));
        pushButton->setText(QCoreApplication::translate("StudentManagerSys", "\346\237\245\350\257\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StudentManagerSys", "\344\277\256\346\224\271", nullptr));
        pushButton_3->setText(QCoreApplication::translate("StudentManagerSys", "\345\242\236\345\212\240", nullptr));
        pushButton_4->setText(QCoreApplication::translate("StudentManagerSys", "\345\210\240\351\231\244", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("StudentManagerSys", "\347\224\267", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("StudentManagerSys", "\345\245\263", nullptr));

        btnClassUpdate->setText(QCoreApplication::translate("StudentManagerSys", "\344\277\256\346\224\271", nullptr));
        btnClassAdd->setText(QCoreApplication::translate("StudentManagerSys", "\345\242\236\345\212\240", nullptr));
        btnClassDel->setText(QCoreApplication::translate("StudentManagerSys", "\345\210\240\351\231\244", nullptr));
        lEditTeacher->setPlaceholderText(QCoreApplication::translate("StudentManagerSys", "\350\200\201\345\270\210\345\220\215", nullptr));
        lEditClassName->setPlaceholderText(QCoreApplication::translate("StudentManagerSys", "\350\257\276\347\250\213\345\220\215", nullptr));
        btnClassGet->setText(QCoreApplication::translate("StudentManagerSys", "\346\237\245\350\257\242", nullptr));
        lEditClassID->setPlaceholderText(QCoreApplication::translate("StudentManagerSys", "\350\257\276\347\250\213\345\217\267", nullptr));
        lineEdit_7->setText(QCoreApplication::translate("StudentManagerSys", "\345\255\246\345\217\267", nullptr));
        lineEdit_8->setText(QCoreApplication::translate("StudentManagerSys", "\345\247\223\345\220\215", nullptr));
        lineEdit_9->setText(QCoreApplication::translate("StudentManagerSys", "\350\257\276\347\250\213\345\220\215", nullptr));
        pushButton_13->setText(QCoreApplication::translate("StudentManagerSys", "\346\237\245\350\257\242", nullptr));
        pushButton_14->setText(QCoreApplication::translate("StudentManagerSys", "\344\277\256\346\224\271", nullptr));
        pushButton_15->setText(QCoreApplication::translate("StudentManagerSys", "\345\242\236\345\212\240", nullptr));
        pushButton_16->setText(QCoreApplication::translate("StudentManagerSys", "\345\210\240\351\231\244", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("StudentManagerSys", "\350\257\276\347\250\213\345\220\215", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("StudentManagerSys", "\350\257\276\347\250\213\345\217\267", nullptr));
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("StudentManagerSys", "\350\200\201\345\270\210\345\220\215", nullptr));
        pushButton_5->setText(QCoreApplication::translate("StudentManagerSys", "\345\242\236\345\212\240", nullptr));
        pushButton_6->setText(QCoreApplication::translate("StudentManagerSys", "\345\210\240\351\231\244", nullptr));
        pushButton_7->setText(QCoreApplication::translate("StudentManagerSys", "\344\277\256\346\224\271", nullptr));
        pushButton_8->setText(QCoreApplication::translate("StudentManagerSys", "\346\237\245\350\257\242", nullptr));
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

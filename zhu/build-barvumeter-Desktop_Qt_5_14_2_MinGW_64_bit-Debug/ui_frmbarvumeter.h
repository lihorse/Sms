/********************************************************************************
** Form generated from reading UI file 'frmbarvumeter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMBARVUMETER_H
#define UI_FRMBARVUMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "barvumeter.h"

QT_BEGIN_NAMESPACE

class Ui_frmBarVUMeter
{
public:
    QHBoxLayout *horizontalLayout;
    BarVUMeter *barVUMeter1;
    BarVUMeter *barVUMeter2;
    BarVUMeter *barVUMeter3;
    BarVUMeter *barVUMeter4;
    BarVUMeter *barVUMeter5;
    BarVUMeter *barVUMeter6;

    void setupUi(QWidget *frmBarVUMeter)
    {
        if (frmBarVUMeter->objectName().isEmpty())
            frmBarVUMeter->setObjectName(QString::fromUtf8("frmBarVUMeter"));
        frmBarVUMeter->resize(500, 300);
        horizontalLayout = new QHBoxLayout(frmBarVUMeter);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        barVUMeter1 = new BarVUMeter(frmBarVUMeter);
        barVUMeter1->setObjectName(QString::fromUtf8("barVUMeter1"));

        horizontalLayout->addWidget(barVUMeter1);

        barVUMeter2 = new BarVUMeter(frmBarVUMeter);
        barVUMeter2->setObjectName(QString::fromUtf8("barVUMeter2"));

        horizontalLayout->addWidget(barVUMeter2);

        barVUMeter3 = new BarVUMeter(frmBarVUMeter);
        barVUMeter3->setObjectName(QString::fromUtf8("barVUMeter3"));

        horizontalLayout->addWidget(barVUMeter3);

        barVUMeter4 = new BarVUMeter(frmBarVUMeter);
        barVUMeter4->setObjectName(QString::fromUtf8("barVUMeter4"));

        horizontalLayout->addWidget(barVUMeter4);

        barVUMeter5 = new BarVUMeter(frmBarVUMeter);
        barVUMeter5->setObjectName(QString::fromUtf8("barVUMeter5"));

        horizontalLayout->addWidget(barVUMeter5);

        barVUMeter6 = new BarVUMeter(frmBarVUMeter);
        barVUMeter6->setObjectName(QString::fromUtf8("barVUMeter6"));

        horizontalLayout->addWidget(barVUMeter6);


        retranslateUi(frmBarVUMeter);

        QMetaObject::connectSlotsByName(frmBarVUMeter);
    } // setupUi

    void retranslateUi(QWidget *frmBarVUMeter)
    {
        frmBarVUMeter->setWindowTitle(QCoreApplication::translate("frmBarVUMeter", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmBarVUMeter: public Ui_frmBarVUMeter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMBARVUMETER_H

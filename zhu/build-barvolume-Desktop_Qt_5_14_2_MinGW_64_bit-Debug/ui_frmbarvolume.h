/********************************************************************************
** Form generated from reading UI file 'frmbarvolume.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMBARVOLUME_H
#define UI_FRMBARVOLUME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QWidget>
#include "barvolume.h"

QT_BEGIN_NAMESPACE

class Ui_frmBarVolume
{
public:
    QHBoxLayout *horizontalLayout;
    BarVolume *barVolume1;
    BarVolume *barVolume2;
    BarVolume *barVolume3;
    BarVolume *barVolume4;
    BarVolume *barVolume5;

    void setupUi(QWidget *frmBarVolume)
    {
        if (frmBarVolume->objectName().isEmpty())
            frmBarVolume->setObjectName(QString::fromUtf8("frmBarVolume"));
        frmBarVolume->resize(500, 300);
        horizontalLayout = new QHBoxLayout(frmBarVolume);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        barVolume1 = new BarVolume(frmBarVolume);
        barVolume1->setObjectName(QString::fromUtf8("barVolume1"));

        horizontalLayout->addWidget(barVolume1);

        barVolume2 = new BarVolume(frmBarVolume);
        barVolume2->setObjectName(QString::fromUtf8("barVolume2"));
        barVolume2->setValue(0);

        horizontalLayout->addWidget(barVolume2);

        barVolume3 = new BarVolume(frmBarVolume);
        barVolume3->setObjectName(QString::fromUtf8("barVolume3"));

        horizontalLayout->addWidget(barVolume3);

        barVolume4 = new BarVolume(frmBarVolume);
        barVolume4->setObjectName(QString::fromUtf8("barVolume4"));

        horizontalLayout->addWidget(barVolume4);

        barVolume5 = new BarVolume(frmBarVolume);
        barVolume5->setObjectName(QString::fromUtf8("barVolume5"));

        horizontalLayout->addWidget(barVolume5);


        retranslateUi(frmBarVolume);

        QMetaObject::connectSlotsByName(frmBarVolume);
    } // setupUi

    void retranslateUi(QWidget *frmBarVolume)
    {
        frmBarVolume->setWindowTitle(QCoreApplication::translate("frmBarVolume", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmBarVolume: public Ui_frmBarVolume {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMBARVOLUME_H

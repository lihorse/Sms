/********************************************************************************
** Form generated from reading UI file 'frmprogressround.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMPROGRESSROUND_H
#define UI_FRMPROGRESSROUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "progressround.h"

QT_BEGIN_NAMESPACE

class Ui_frmProgressRound
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    ProgressRound *progressRound1;
    ProgressRound *progressRound2;
    ProgressRound *progressRound3;
    ProgressRound *progressRound4;
    ProgressRound *progressRound5;
    ProgressRound *progressRound6;
    QSlider *slider;

    void setupUi(QWidget *frmProgressRound)
    {
        if (frmProgressRound->objectName().isEmpty())
            frmProgressRound->setObjectName(QString::fromUtf8("frmProgressRound"));
        frmProgressRound->resize(500, 300);
        frmProgressRound->setStyleSheet(QString::fromUtf8("QWidget#widget{background-color: rgb(0, 85, 127);}\n"
"QLabel{color:rgb(255,255,255);}\n"
""));
        verticalLayout = new QVBoxLayout(frmProgressRound);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(frmProgressRound);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label1 = new QLabel(widget);
        label1->setObjectName(QString::fromUtf8("label1"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label1->sizePolicy().hasHeightForWidth());
        label1->setSizePolicy(sizePolicy);
        label1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label1, 0, 0, 1, 1);

        label2 = new QLabel(widget);
        label2->setObjectName(QString::fromUtf8("label2"));
        sizePolicy.setHeightForWidth(label2->sizePolicy().hasHeightForWidth());
        label2->setSizePolicy(sizePolicy);
        label2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label2, 0, 1, 1, 1);

        label3 = new QLabel(widget);
        label3->setObjectName(QString::fromUtf8("label3"));
        sizePolicy.setHeightForWidth(label3->sizePolicy().hasHeightForWidth());
        label3->setSizePolicy(sizePolicy);
        label3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label3, 0, 2, 1, 1);

        progressRound1 = new ProgressRound(widget);
        progressRound1->setObjectName(QString::fromUtf8("progressRound1"));

        gridLayout->addWidget(progressRound1, 1, 0, 1, 1);

        progressRound2 = new ProgressRound(widget);
        progressRound2->setObjectName(QString::fromUtf8("progressRound2"));

        gridLayout->addWidget(progressRound2, 1, 1, 1, 1);

        progressRound3 = new ProgressRound(widget);
        progressRound3->setObjectName(QString::fromUtf8("progressRound3"));

        gridLayout->addWidget(progressRound3, 1, 2, 1, 1);

        progressRound4 = new ProgressRound(widget);
        progressRound4->setObjectName(QString::fromUtf8("progressRound4"));

        gridLayout->addWidget(progressRound4, 2, 0, 1, 1);

        progressRound5 = new ProgressRound(widget);
        progressRound5->setObjectName(QString::fromUtf8("progressRound5"));

        gridLayout->addWidget(progressRound5, 2, 1, 1, 1);

        progressRound6 = new ProgressRound(widget);
        progressRound6->setObjectName(QString::fromUtf8("progressRound6"));

        gridLayout->addWidget(progressRound6, 2, 2, 1, 1);

        slider = new QSlider(widget);
        slider->setObjectName(QString::fromUtf8("slider"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(slider->sizePolicy().hasHeightForWidth());
        slider->setSizePolicy(sizePolicy1);
        slider->setMaximum(1000);
        slider->setValue(300);
        slider->setOrientation(Qt::Horizontal);
        slider->setTickPosition(QSlider::TicksBothSides);
        slider->setTickInterval(25);

        gridLayout->addWidget(slider, 3, 0, 1, 3);


        verticalLayout->addWidget(widget);


        retranslateUi(frmProgressRound);

        QMetaObject::connectSlotsByName(frmProgressRound);
    } // setupUi

    void retranslateUi(QWidget *frmProgressRound)
    {
        frmProgressRound->setWindowTitle(QCoreApplication::translate("frmProgressRound", "Form", nullptr));
        label1->setText(QCoreApplication::translate("frmProgressRound", "\345\234\206\347\216\257\351\243\216\346\240\274", nullptr));
        label2->setText(QCoreApplication::translate("frmProgressRound", "\351\245\274\347\212\266\351\243\216\346\240\274", nullptr));
        label3->setText(QCoreApplication::translate("frmProgressRound", "\347\272\277\346\235\241\351\243\216\346\240\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class frmProgressRound: public Ui_frmProgressRound {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMPROGRESSROUND_H

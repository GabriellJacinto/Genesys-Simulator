/********************************************************************************
** Form generated from reading UI file 'DialogTimerConfigure.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGTIMERCONFIGURE_H
#define UI_DIALOGTIMERCONFIGURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogTimerConfigure
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupFormatTime;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayoutFormatTime;
    QRadioButton *radioButtonTwelve;
    QRadioButton *radioButtonTwentyFour;
    QGroupBox *groupStartTime;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayoutStartTime;
    QVBoxLayout *verticalLayoutHour;
    QLabel *labelHour;
    QSpinBox *spinBoxHour;
    QVBoxLayout *verticalLayoutMinute;
    QLabel *labelMinute;
    QSpinBox *spinBoxMinute;
    QVBoxLayout *verticalLayoutSecond;
    QLabel *labelSecond;
    QSpinBox *spinBoxSecond;

    void setupUi(QDialog *DialogTimerConfigure)
    {
        if (DialogTimerConfigure->objectName().isEmpty())
            DialogTimerConfigure->setObjectName(QString::fromUtf8("DialogTimerConfigure"));
        DialogTimerConfigure->resize(392, 159);
        buttonBox = new QDialogButtonBox(DialogTimerConfigure);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 120, 371, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupFormatTime = new QGroupBox(DialogTimerConfigure);
        groupFormatTime->setObjectName(QString::fromUtf8("groupFormatTime"));
        groupFormatTime->setGeometry(QRect(280, 10, 101, 91));
        layoutWidget_3 = new QWidget(groupFormatTime);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 30, 88, 54));
        verticalLayoutFormatTime = new QVBoxLayout(layoutWidget_3);
        verticalLayoutFormatTime->setObjectName(QString::fromUtf8("verticalLayoutFormatTime"));
        verticalLayoutFormatTime->setContentsMargins(0, 0, 0, 0);
        radioButtonTwelve = new QRadioButton(layoutWidget_3);
        radioButtonTwelve->setObjectName(QString::fromUtf8("radioButtonTwelve"));
        radioButtonTwelve->setChecked(true);

        verticalLayoutFormatTime->addWidget(radioButtonTwelve);

        radioButtonTwentyFour = new QRadioButton(layoutWidget_3);
        radioButtonTwentyFour->setObjectName(QString::fromUtf8("radioButtonTwentyFour"));

        verticalLayoutFormatTime->addWidget(radioButtonTwentyFour);

        groupStartTime = new QGroupBox(DialogTimerConfigure);
        groupStartTime->setObjectName(QString::fromUtf8("groupStartTime"));
        groupStartTime->setGeometry(QRect(10, 10, 241, 91));
        layoutWidget_4 = new QWidget(groupStartTime);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 30, 221, 53));
        horizontalLayoutStartTime = new QHBoxLayout(layoutWidget_4);
        horizontalLayoutStartTime->setObjectName(QString::fromUtf8("horizontalLayoutStartTime"));
        horizontalLayoutStartTime->setContentsMargins(0, 0, 0, 0);
        verticalLayoutHour = new QVBoxLayout();
        verticalLayoutHour->setObjectName(QString::fromUtf8("verticalLayoutHour"));
        labelHour = new QLabel(layoutWidget_4);
        labelHour->setObjectName(QString::fromUtf8("labelHour"));

        verticalLayoutHour->addWidget(labelHour);

        spinBoxHour = new QSpinBox(layoutWidget_4);
        spinBoxHour->setObjectName(QString::fromUtf8("spinBoxHour"));
        spinBoxHour->setMaximum(12);

        verticalLayoutHour->addWidget(spinBoxHour);


        horizontalLayoutStartTime->addLayout(verticalLayoutHour);

        verticalLayoutMinute = new QVBoxLayout();
        verticalLayoutMinute->setObjectName(QString::fromUtf8("verticalLayoutMinute"));
        labelMinute = new QLabel(layoutWidget_4);
        labelMinute->setObjectName(QString::fromUtf8("labelMinute"));

        verticalLayoutMinute->addWidget(labelMinute);

        spinBoxMinute = new QSpinBox(layoutWidget_4);
        spinBoxMinute->setObjectName(QString::fromUtf8("spinBoxMinute"));
        spinBoxMinute->setMaximum(60);

        verticalLayoutMinute->addWidget(spinBoxMinute);


        horizontalLayoutStartTime->addLayout(verticalLayoutMinute);

        verticalLayoutSecond = new QVBoxLayout();
        verticalLayoutSecond->setObjectName(QString::fromUtf8("verticalLayoutSecond"));
        labelSecond = new QLabel(layoutWidget_4);
        labelSecond->setObjectName(QString::fromUtf8("labelSecond"));

        verticalLayoutSecond->addWidget(labelSecond);

        spinBoxSecond = new QSpinBox(layoutWidget_4);
        spinBoxSecond->setObjectName(QString::fromUtf8("spinBoxSecond"));
        spinBoxSecond->setMaximum(60);

        verticalLayoutSecond->addWidget(spinBoxSecond);


        horizontalLayoutStartTime->addLayout(verticalLayoutSecond);


        retranslateUi(DialogTimerConfigure);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogTimerConfigure, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogTimerConfigure, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogTimerConfigure);
    } // setupUi

    void retranslateUi(QDialog *DialogTimerConfigure)
    {
        DialogTimerConfigure->setWindowTitle(QCoreApplication::translate("DialogTimerConfigure", "Configure Timer", nullptr));
        groupFormatTime->setTitle(QCoreApplication::translate("DialogTimerConfigure", "Format Time", nullptr));
        radioButtonTwelve->setText(QCoreApplication::translate("DialogTimerConfigure", "12 Hours", nullptr));
        radioButtonTwentyFour->setText(QCoreApplication::translate("DialogTimerConfigure", "24 Hours", nullptr));
        groupStartTime->setTitle(QCoreApplication::translate("DialogTimerConfigure", "Start Time", nullptr));
        labelHour->setText(QCoreApplication::translate("DialogTimerConfigure", "Hour", nullptr));
        labelMinute->setText(QCoreApplication::translate("DialogTimerConfigure", "Minute", nullptr));
        labelSecond->setText(QCoreApplication::translate("DialogTimerConfigure", "Second", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogTimerConfigure: public Ui_DialogTimerConfigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGTIMERCONFIGURE_H

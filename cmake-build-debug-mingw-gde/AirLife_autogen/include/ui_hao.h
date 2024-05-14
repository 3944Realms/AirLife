/********************************************************************************
** Form generated from reading UI file 'hao.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HAO_H
#define UI_HAO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HpyMte__aap_ohrsDy
{
public:
    QCalendarWidget *calendarWidget;
    QLCDNumber *lcdNumber;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *HpyMte__aap_ohrsDy)
    {
        if (HpyMte__aap_ohrsDy->objectName().isEmpty())
            HpyMte__aap_ohrsDy->setObjectName(QString::fromUtf8("HpyMte__aap_ohrsDy"));
        HpyMte__aap_ohrsDy->resize(1058, 348);
        HpyMte__aap_ohrsDy->setMinimumSize(QSize(1058, 348));
        HpyMte__aap_ohrsDy->setMaximumSize(QSize(1058, 348));
        calendarWidget = new QCalendarWidget(HpyMte__aap_ohrsDy);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(67, 30, 301, 221));
        lcdNumber = new QLCDNumber(HpyMte__aap_ohrsDy);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(430, 90, 231, 121));
        lcdNumber->setDigitCount(8);
        lcdNumber->setProperty("intValue", QVariant(20240512));
        label = new QLabel(HpyMte__aap_ohrsDy);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(380, 160, 341, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font.setPointSize(26);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(HpyMte__aap_ohrsDy);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(660, 210, 391, 141));
        label_2->setMaximumSize(QSize(391, 141));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::PlainText);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(HpyMte__aap_ohrsDy);

        QMetaObject::connectSlotsByName(HpyMte__aap_ohrsDy);
    } // setupUi

    void retranslateUi(QWidget *HpyMte__aap_ohrsDy)
    {
        HpyMte__aap_ohrsDy->setWindowTitle(QCoreApplication::translate("HpyMte__aap_ohrsDy", "HpyMte__aap_ohrsDy", nullptr));
        label->setText(QCoreApplication::translate("HpyMte__aap_ohrsDy", "\346\257\215\344\272\262\350\212\202\345\277\253\344\271\220", nullptr));
        label_2->setText(QCoreApplication::translate("HpyMte__aap_ohrsDy", "-\350\207\264\345\256\236\344\270\226\347\225\214\344\270\212\346\234\200\345\217\257\347\210\261\347\232\204\344\272\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HpyMte__aap_ohrsDy: public Ui_HpyMte__aap_ohrsDy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HAO_H

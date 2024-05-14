/********************************************************************************
** Form generated from reading UI file 'hui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUI_H
#define UI_HUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

namespace egg {

class Ui_hui
{
public:
    QLabel *label_2;
    QCalendarWidget *calendarWidget;
    QLCDNumber *lcdNumber;
    QLabel *label;

    void setupUi(QWidget *egg__hui)
    {
        if (egg__hui->objectName().isEmpty())
            egg__hui->setObjectName(QString::fromUtf8("egg__hui"));
        egg__hui->resize(1017, 386);
        label_2 = new QLabel(egg__hui);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(610, 250, 391, 141));
        label_2->setMaximumSize(QSize(391, 141));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font.setPointSize(26);
        label_2->setFont(font);
        label_2->setTextFormat(Qt::PlainText);
        label_2->setAlignment(Qt::AlignCenter);
        calendarWidget = new QCalendarWidget(egg__hui);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(17, 70, 301, 221));
        lcdNumber = new QLCDNumber(egg__hui);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(380, 130, 231, 121));
        lcdNumber->setDigitCount(8);
        lcdNumber->setProperty("intValue", QVariant(20240512));
        label = new QLabel(egg__hui);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(330, 200, 341, 141));
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(egg__hui);

        QMetaObject::connectSlotsByName(egg__hui);
    } // setupUi

    void retranslateUi(QWidget *egg__hui)
    {
        egg__hui->setWindowTitle(QCoreApplication::translate("egg::hui", "hui", nullptr));
        label_2->setText(QCoreApplication::translate("egg::hui", "-\350\207\264\345\256\236\344\270\226\347\225\214\344\270\212\346\234\200\345\217\257\347\210\261\347\232\204\344\272\272", nullptr));
        label->setText(QCoreApplication::translate("egg::hui", "\346\257\215\344\272\262\350\212\202\345\277\253\344\271\220", nullptr));
    } // retranslateUi

};

} // namespace egg

namespace egg {
namespace Ui {
    class hui: public Ui_hui {};
} // namespace Ui
} // namespace egg

#endif // UI_HUI_H

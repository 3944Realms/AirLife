/********************************************************************************
** Form generated from reading UI file 'testwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWINDOWS_H
#define UI_TESTWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testWindows
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *account_lab;
    QTextEdit *AccountInput;
    QSpacerItem *horizontalSpacer;
    QTextEdit *PasswordInput;
    QLabel *password_lab;

    void setupUi(QWidget *testWindows)
    {
        if (testWindows->objectName().isEmpty())
            testWindows->setObjectName(QString::fromUtf8("testWindows"));
        testWindows->resize(561, 379);
        testWindows->setMinimumSize(QSize(561, 379));
        testWindows->setMaximumSize(QSize(561, 379));
        pushButton = new QPushButton(testWindows);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 220, 201, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Bauhaus 93"));
        font.setPointSize(12);
        pushButton->setFont(font);
        widget = new QWidget(testWindows);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 80, 391, 91));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        account_lab = new QLabel(widget);
        account_lab->setObjectName(QString::fromUtf8("account_lab"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Alte DIN 1451 Mittelschrift gep"));
        account_lab->setFont(font1);
        account_lab->setTabletTracking(false);
        account_lab->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(account_lab, 0, 0, 1, 2);

        AccountInput = new QTextEdit(widget);
        AccountInput->setObjectName(QString::fromUtf8("AccountInput"));
        AccountInput->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AccountInput->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(AccountInput, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(448, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 2, 3);

        PasswordInput = new QTextEdit(widget);
        PasswordInput->setObjectName(QString::fromUtf8("PasswordInput"));
        PasswordInput->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        PasswordInput->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(PasswordInput, 3, 2, 1, 1);

        password_lab = new QLabel(widget);
        password_lab->setObjectName(QString::fromUtf8("password_lab"));
        password_lab->setFont(font1);
        password_lab->setTabletTracking(false);
        password_lab->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(password_lab, 3, 1, 1, 1);


        retranslateUi(testWindows);

        QMetaObject::connectSlotsByName(testWindows);
    } // setupUi

    void retranslateUi(QWidget *testWindows)
    {
        testWindows->setWindowTitle(QCoreApplication::translate("testWindows", "testWindows", nullptr));
        pushButton->setText(QCoreApplication::translate("testWindows", "Push me", nullptr));
        account_lab->setText(QCoreApplication::translate("testWindows", "Account", nullptr));
        password_lab->setText(QCoreApplication::translate("testWindows", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testWindows: public Ui_testWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWINDOWS_H

/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace airLifeDialog {

class Ui_loginDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *acc_lab;
    QLineEdit *acc_inp;
    QLabel *pas_lab;
    QLineEdit *pas_inp;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *airLifeDialog__loginDialog)
    {
        if (airLifeDialog__loginDialog->objectName().isEmpty())
            airLifeDialog__loginDialog->setObjectName(QString::fromUtf8("airLifeDialog__loginDialog"));
        airLifeDialog__loginDialog->resize(500, 250);
        airLifeDialog__loginDialog->setMinimumSize(QSize(500, 250));
        airLifeDialog__loginDialog->setMaximumSize(QSize(500, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeDialog__loginDialog->setWindowIcon(icon);
        verticalLayoutWidget = new QWidget(airLifeDialog__loginDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 60, 351, 151));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        acc_lab = new QLabel(verticalLayoutWidget);
        acc_lab->setObjectName(QString::fromUtf8("acc_lab"));
        acc_lab->setLayoutDirection(Qt::LeftToRight);
        acc_lab->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(acc_lab, 0, 0, 1, 1);

        acc_inp = new QLineEdit(verticalLayoutWidget);
        acc_inp->setObjectName(QString::fromUtf8("acc_inp"));

        gridLayout->addWidget(acc_inp, 0, 1, 1, 1);

        pas_lab = new QLabel(verticalLayoutWidget);
        pas_lab->setObjectName(QString::fromUtf8("pas_lab"));
        pas_lab->setLayoutDirection(Qt::LeftToRight);
        pas_lab->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(pas_lab, 1, 0, 1, 1);

        pas_inp = new QLineEdit(verticalLayoutWidget);
        pas_inp->setObjectName(QString::fromUtf8("pas_inp"));
        pas_inp->setEchoMode(QLineEdit::PasswordEchoOnEdit);

        gridLayout->addWidget(pas_inp, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loginButton = new QPushButton(verticalLayoutWidget);
        loginButton->setObjectName(QString::fromUtf8("loginButton"));

        horizontalLayout->addWidget(loginButton);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(airLifeDialog__loginDialog);

        QMetaObject::connectSlotsByName(airLifeDialog__loginDialog);
    } // setupUi

    void retranslateUi(QDialog *airLifeDialog__loginDialog)
    {
        airLifeDialog__loginDialog->setWindowTitle(QCoreApplication::translate("airLifeDialog::loginDialog", "\347\231\273\345\275\225", nullptr));
        acc_lab->setText(QCoreApplication::translate("airLifeDialog::loginDialog", "\350\264\246\345\217\267\357\274\232", nullptr));
        pas_lab->setText(QCoreApplication::translate("airLifeDialog::loginDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        loginButton->setText(QCoreApplication::translate("airLifeDialog::loginDialog", "\347\231\273\345\275\225(&L)", nullptr));
        cancelButton->setText(QCoreApplication::translate("airLifeDialog::loginDialog", "\345\217\226\346\266\210(&C)", nullptr));
    } // retranslateUi

};

} // namespace airLifeDialog

namespace airLifeDialog {
namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui
} // namespace airLifeDialog

#endif // UI_LOGINDIALOG_H

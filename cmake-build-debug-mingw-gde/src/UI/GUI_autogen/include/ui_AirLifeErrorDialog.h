/********************************************************************************
** Form generated from reading UI file 'airlifeerrordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRLIFEERRORDIALOG_H
#define UI_AIRLIFEERRORDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

namespace airLifeDialog {

class Ui_AirLifeErrorDialog
{
public:
    QLabel *airLifeImageLabel;
    QTextBrowser *airLifeErrorLogOutput;
    QPushButton *airLifeSurePushButton;

    void setupUi(QDialog *airLifeDialog__AirLifeErrorDialog)
    {
        if (airLifeDialog__AirLifeErrorDialog->objectName().isEmpty())
            airLifeDialog__AirLifeErrorDialog->setObjectName(QString::fromUtf8("airLifeDialog__AirLifeErrorDialog"));
        airLifeDialog__AirLifeErrorDialog->resize(500, 250);
        airLifeDialog__AirLifeErrorDialog->setMinimumSize(QSize(500, 250));
        airLifeDialog__AirLifeErrorDialog->setMaximumSize(QSize(500, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeDialog__AirLifeErrorDialog->setWindowIcon(icon);
        airLifeImageLabel = new QLabel(airLifeDialog__AirLifeErrorDialog);
        airLifeImageLabel->setObjectName(QString::fromUtf8("airLifeImageLabel"));
        airLifeImageLabel->setGeometry(QRect(20, 50, 71, 71));
        airLifeImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/Appimg/SymbolsError.png")));
        airLifeImageLabel->setScaledContents(true);
        airLifeErrorLogOutput = new QTextBrowser(airLifeDialog__AirLifeErrorDialog);
        airLifeErrorLogOutput->setObjectName(QString::fromUtf8("airLifeErrorLogOutput"));
        airLifeErrorLogOutput->setGeometry(QRect(120, 20, 349, 181));
        airLifeSurePushButton = new QPushButton(airLifeDialog__AirLifeErrorDialog);
        airLifeSurePushButton->setObjectName(QString::fromUtf8("airLifeSurePushButton"));
        airLifeSurePushButton->setGeometry(QRect(400, 210, 75, 23));

        retranslateUi(airLifeDialog__AirLifeErrorDialog);

        QMetaObject::connectSlotsByName(airLifeDialog__AirLifeErrorDialog);
    } // setupUi

    void retranslateUi(QDialog *airLifeDialog__AirLifeErrorDialog)
    {
        airLifeDialog__AirLifeErrorDialog->setWindowTitle(QCoreApplication::translate("airLifeDialog::AirLifeErrorDialog", "\351\224\231\350\257\257", nullptr));
        airLifeImageLabel->setText(QString());
        airLifeSurePushButton->setText(QCoreApplication::translate("airLifeDialog::AirLifeErrorDialog", "\346\230\216\347\231\275(&C)", nullptr));
    } // retranslateUi

};

} // namespace airLifeDialog

namespace airLifeDialog {
namespace Ui {
    class AirLifeErrorDialog: public Ui_AirLifeErrorDialog {};
} // namespace Ui
} // namespace airLifeDialog

#endif // UI_AIRLIFEERRORDIALOG_H

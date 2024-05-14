/********************************************************************************
** Form generated from reading UI file 'airliferunnigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRLIFERUNNIGDIALOG_H
#define UI_AIRLIFERUNNIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace airLifeDialog {

class Ui_AirLifeRunnigDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *airLifeLogOutput;
    QProgressBar *airLifeProgressBar;
    QLabel *airLifeImageLabel;

    void setupUi(QDialog *airLifeDialog__AirLifeRunnigDialog)
    {
        if (airLifeDialog__AirLifeRunnigDialog->objectName().isEmpty())
            airLifeDialog__AirLifeRunnigDialog->setObjectName(QString::fromUtf8("airLifeDialog__AirLifeRunnigDialog"));
        airLifeDialog__AirLifeRunnigDialog->setWindowModality(Qt::NonModal);
        airLifeDialog__AirLifeRunnigDialog->resize(500, 250);
        airLifeDialog__AirLifeRunnigDialog->setMinimumSize(QSize(500, 250));
        airLifeDialog__AirLifeRunnigDialog->setMaximumSize(QSize(500, 250));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Active, QIcon::On);
        airLifeDialog__AirLifeRunnigDialog->setWindowIcon(icon);
        airLifeDialog__AirLifeRunnigDialog->setInputMethodHints(Qt::ImhNone);
        verticalLayoutWidget = new QWidget(airLifeDialog__AirLifeRunnigDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 40, 351, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        airLifeLogOutput = new QTextBrowser(verticalLayoutWidget);
        airLifeLogOutput->setObjectName(QString::fromUtf8("airLifeLogOutput"));

        verticalLayout->addWidget(airLifeLogOutput);

        airLifeProgressBar = new QProgressBar(verticalLayoutWidget);
        airLifeProgressBar->setObjectName(QString::fromUtf8("airLifeProgressBar"));
        airLifeProgressBar->setValue(0);

        verticalLayout->addWidget(airLifeProgressBar);

        airLifeImageLabel = new QLabel(airLifeDialog__AirLifeRunnigDialog);
        airLifeImageLabel->setObjectName(QString::fromUtf8("airLifeImageLabel"));
        airLifeImageLabel->setGeometry(QRect(30, 60, 71, 71));
        airLifeImageLabel->setPixmap(QPixmap(QString::fromUtf8(":/Appimg/SymbolsInfo.png")));
        airLifeImageLabel->setScaledContents(true);

        retranslateUi(airLifeDialog__AirLifeRunnigDialog);

        QMetaObject::connectSlotsByName(airLifeDialog__AirLifeRunnigDialog);
    } // setupUi

    void retranslateUi(QDialog *airLifeDialog__AirLifeRunnigDialog)
    {
        airLifeDialog__AirLifeRunnigDialog->setWindowTitle(QCoreApplication::translate("airLifeDialog::AirLifeRunnigDialog", "\350\277\220\350\241\214\344\270\255", nullptr));
        airLifeImageLabel->setText(QString());
    } // retranslateUi

};

} // namespace airLifeDialog

namespace airLifeDialog {
namespace Ui {
    class AirLifeRunnigDialog: public Ui_AirLifeRunnigDialog {};
} // namespace Ui
} // namespace airLifeDialog

#endif // UI_AIRLIFERUNNIGDIALOG_H

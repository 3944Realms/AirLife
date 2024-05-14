/********************************************************************************
** Form generated from reading UI file 'airlifeinfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRLIFEINFODIALOG_H
#define UI_AIRLIFEINFODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace airLifeDialog {

class Ui_AirLifeInfoDialog
{
public:
    QLabel *airLifeFlightLabel;
    QComboBox *airLifeFlightComboBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *airLifeSELabel;
    QLineEdit *airLifeSLineEdit;
    QLabel *airLifeArrowLabel;
    QLineEdit *airLifeELineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *airLifeSTimeELabel;
    QLineEdit *airLifeTimeLineEdit;
    QPushButton *airLifeBackPushButton;

    void setupUi(QDialog *airLifeDialog__AirLifeInfoDialog)
    {
        if (airLifeDialog__AirLifeInfoDialog->objectName().isEmpty())
            airLifeDialog__AirLifeInfoDialog->setObjectName(QString::fromUtf8("airLifeDialog__AirLifeInfoDialog"));
        airLifeDialog__AirLifeInfoDialog->setEnabled(true);
        airLifeDialog__AirLifeInfoDialog->resize(500, 250);
        airLifeDialog__AirLifeInfoDialog->setMinimumSize(QSize(500, 250));
        airLifeDialog__AirLifeInfoDialog->setMaximumSize(QSize(500, 250));
        airLifeDialog__AirLifeInfoDialog->setMouseTracking(false);
        airLifeDialog__AirLifeInfoDialog->setAcceptDrops(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeDialog__AirLifeInfoDialog->setWindowIcon(icon);
        airLifeFlightLabel = new QLabel(airLifeDialog__AirLifeInfoDialog);
        airLifeFlightLabel->setObjectName(QString::fromUtf8("airLifeFlightLabel"));
        airLifeFlightLabel->setGeometry(QRect(60, 30, 51, 41));
        airLifeFlightLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        airLifeFlightComboBox = new QComboBox(airLifeDialog__AirLifeInfoDialog);
        airLifeFlightComboBox->setObjectName(QString::fromUtf8("airLifeFlightComboBox"));
        airLifeFlightComboBox->setGeometry(QRect(100, 40, 331, 19));
        airLifeFlightComboBox->setEditable(true);
        verticalLayoutWidget = new QWidget(airLifeDialog__AirLifeInfoDialog);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 70, 371, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        airLifeSELabel = new QLabel(verticalLayoutWidget);
        airLifeSELabel->setObjectName(QString::fromUtf8("airLifeSELabel"));

        horizontalLayout->addWidget(airLifeSELabel);

        airLifeSLineEdit = new QLineEdit(verticalLayoutWidget);
        airLifeSLineEdit->setObjectName(QString::fromUtf8("airLifeSLineEdit"));
        airLifeSLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(airLifeSLineEdit);

        airLifeArrowLabel = new QLabel(verticalLayoutWidget);
        airLifeArrowLabel->setObjectName(QString::fromUtf8("airLifeArrowLabel"));

        horizontalLayout->addWidget(airLifeArrowLabel);

        airLifeELineEdit = new QLineEdit(verticalLayoutWidget);
        airLifeELineEdit->setObjectName(QString::fromUtf8("airLifeELineEdit"));
        airLifeELineEdit->setReadOnly(true);

        horizontalLayout->addWidget(airLifeELineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        airLifeSTimeELabel = new QLabel(verticalLayoutWidget);
        airLifeSTimeELabel->setObjectName(QString::fromUtf8("airLifeSTimeELabel"));

        horizontalLayout_3->addWidget(airLifeSTimeELabel);

        airLifeTimeLineEdit = new QLineEdit(verticalLayoutWidget);
        airLifeTimeLineEdit->setObjectName(QString::fromUtf8("airLifeTimeLineEdit"));
        airLifeTimeLineEdit->setReadOnly(true);

        horizontalLayout_3->addWidget(airLifeTimeLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        airLifeBackPushButton = new QPushButton(airLifeDialog__AirLifeInfoDialog);
        airLifeBackPushButton->setObjectName(QString::fromUtf8("airLifeBackPushButton"));
        airLifeBackPushButton->setGeometry(QRect(200, 190, 75, 23));

        retranslateUi(airLifeDialog__AirLifeInfoDialog);

        QMetaObject::connectSlotsByName(airLifeDialog__AirLifeInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *airLifeDialog__AirLifeInfoDialog)
    {
        airLifeDialog__AirLifeInfoDialog->setWindowTitle(QCoreApplication::translate("airLifeDialog::AirLifeInfoDialog", "\346\237\245\350\257\242\347\273\223\346\236\234", nullptr));
        airLifeFlightLabel->setText(QCoreApplication::translate("airLifeDialog::AirLifeInfoDialog", "\350\210\252\347\217\255\357\274\232", nullptr));
        airLifeSELabel->setText(QCoreApplication::translate("airLifeDialog::AirLifeInfoDialog", "\350\265\267\347\202\271/\347\273\210\347\202\271\357\274\232", nullptr));
        airLifeArrowLabel->setText(QCoreApplication::translate("airLifeDialog::AirLifeInfoDialog", "--->", nullptr));
        airLifeSTimeELabel->setText(QCoreApplication::translate("airLifeDialog::AirLifeInfoDialog", "\345\217\221\347\217\255\346\227\266\345\210\273\357\274\232", nullptr));
        airLifeBackPushButton->setText(QCoreApplication::translate("airLifeDialog::AirLifeInfoDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

} // namespace airLifeDialog

namespace airLifeDialog {
namespace Ui {
    class AirLifeInfoDialog: public Ui_AirLifeInfoDialog {};
} // namespace Ui
} // namespace airLifeDialog

#endif // UI_AIRLIFEINFODIALOG_H

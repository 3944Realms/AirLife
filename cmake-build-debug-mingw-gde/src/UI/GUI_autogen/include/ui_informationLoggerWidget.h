/********************************************************************************
** Form generated from reading UI file 'informationloggerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONLOGGERWIDGET_H
#define UI_INFORMATIONLOGGERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace airLifeWidget {

class Ui_informationLoggerWidget
{
public:
    QGroupBox *airLifeBaseGroupBox;
    QGroupBox *airLifeAddNewAirplaneGroupBox;
    QPushButton *airLifeAddNewAirplanePushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *airLifeAddNewAirplaneUUIDLineEdit;
    QLabel *airLifeAddNewAirplaneUUIDLabel;
    QLabel *airLifeAddNewAirplaneCapLineLabel;
    QLineEdit *airLifeAddNewAirplaneCapLineEdit;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *airLifeAddNewAreasLabel;
    QLineEdit *airLifeAddNewAreasLineEdit;
    QPushButton *airLifeAddNewAreasPushButton;
    QGroupBox *airLifeFlightGroupBox;
    QLabel *airLifeFlightLabel;
    QComboBox *airLifeFlightComboBox;
    QLabel *airLifeAirplaneUUIDLabel;
    QComboBox *airLifeAirplaneUUIDComboBox;
    QPushButton *airLifeAddNewFlightPushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *airLifeSELabel;
    QComboBox *airLifeEComboBox;
    QLabel *airLifeArrowLabel;
    QComboBox *airLifeSComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *airLifeSTimeELabel;
    QLineEdit *airLifeTimeLineEdit;
    QPushButton *airLifeBackPushButton;

    void setupUi(QWidget *airLifeWidget__informationLoggerWidget)
    {
        if (airLifeWidget__informationLoggerWidget->objectName().isEmpty())
            airLifeWidget__informationLoggerWidget->setObjectName(QString::fromUtf8("airLifeWidget__informationLoggerWidget"));
        airLifeWidget__informationLoggerWidget->resize(840, 400);
        airLifeWidget__informationLoggerWidget->setMinimumSize(QSize(840, 400));
        airLifeWidget__informationLoggerWidget->setMaximumSize(QSize(840, 400));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeWidget__informationLoggerWidget->setWindowIcon(icon);
        airLifeBaseGroupBox = new QGroupBox(airLifeWidget__informationLoggerWidget);
        airLifeBaseGroupBox->setObjectName(QString::fromUtf8("airLifeBaseGroupBox"));
        airLifeBaseGroupBox->setGeometry(QRect(20, 20, 351, 361));
        airLifeAddNewAirplaneGroupBox = new QGroupBox(airLifeBaseGroupBox);
        airLifeAddNewAirplaneGroupBox->setObjectName(QString::fromUtf8("airLifeAddNewAirplaneGroupBox"));
        airLifeAddNewAirplaneGroupBox->setGeometry(QRect(30, 140, 301, 141));
        airLifeAddNewAirplanePushButton = new QPushButton(airLifeAddNewAirplaneGroupBox);
        airLifeAddNewAirplanePushButton->setObjectName(QString::fromUtf8("airLifeAddNewAirplanePushButton"));
        airLifeAddNewAirplanePushButton->setGeometry(QRect(210, 110, 75, 23));
        gridLayoutWidget = new QWidget(airLifeAddNewAirplaneGroupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 30, 241, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        airLifeAddNewAirplaneUUIDLineEdit = new QLineEdit(gridLayoutWidget);
        airLifeAddNewAirplaneUUIDLineEdit->setObjectName(QString::fromUtf8("airLifeAddNewAirplaneUUIDLineEdit"));

        gridLayout->addWidget(airLifeAddNewAirplaneUUIDLineEdit, 0, 1, 1, 1);

        airLifeAddNewAirplaneUUIDLabel = new QLabel(gridLayoutWidget);
        airLifeAddNewAirplaneUUIDLabel->setObjectName(QString::fromUtf8("airLifeAddNewAirplaneUUIDLabel"));

        gridLayout->addWidget(airLifeAddNewAirplaneUUIDLabel, 0, 0, 1, 1);

        airLifeAddNewAirplaneCapLineLabel = new QLabel(gridLayoutWidget);
        airLifeAddNewAirplaneCapLineLabel->setObjectName(QString::fromUtf8("airLifeAddNewAirplaneCapLineLabel"));

        gridLayout->addWidget(airLifeAddNewAirplaneCapLineLabel, 1, 0, 1, 1);

        airLifeAddNewAirplaneCapLineEdit = new QLineEdit(gridLayoutWidget);
        airLifeAddNewAirplaneCapLineEdit->setObjectName(QString::fromUtf8("airLifeAddNewAirplaneCapLineEdit"));

        gridLayout->addWidget(airLifeAddNewAirplaneCapLineEdit, 1, 1, 1, 1);

        horizontalLayoutWidget = new QWidget(airLifeBaseGroupBox);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(40, 30, 281, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        airLifeAddNewAreasLabel = new QLabel(horizontalLayoutWidget);
        airLifeAddNewAreasLabel->setObjectName(QString::fromUtf8("airLifeAddNewAreasLabel"));

        horizontalLayout->addWidget(airLifeAddNewAreasLabel);

        airLifeAddNewAreasLineEdit = new QLineEdit(horizontalLayoutWidget);
        airLifeAddNewAreasLineEdit->setObjectName(QString::fromUtf8("airLifeAddNewAreasLineEdit"));

        horizontalLayout->addWidget(airLifeAddNewAreasLineEdit);

        airLifeAddNewAreasPushButton = new QPushButton(horizontalLayoutWidget);
        airLifeAddNewAreasPushButton->setObjectName(QString::fromUtf8("airLifeAddNewAreasPushButton"));

        horizontalLayout->addWidget(airLifeAddNewAreasPushButton);

        airLifeFlightGroupBox = new QGroupBox(airLifeWidget__informationLoggerWidget);
        airLifeFlightGroupBox->setObjectName(QString::fromUtf8("airLifeFlightGroupBox"));
        airLifeFlightGroupBox->setGeometry(QRect(390, 20, 441, 281));
        airLifeFlightLabel = new QLabel(airLifeFlightGroupBox);
        airLifeFlightLabel->setObjectName(QString::fromUtf8("airLifeFlightLabel"));
        airLifeFlightLabel->setGeometry(QRect(40, 20, 61, 41));
        airLifeFlightLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        airLifeFlightComboBox = new QComboBox(airLifeFlightGroupBox);
        airLifeFlightComboBox->setObjectName(QString::fromUtf8("airLifeFlightComboBox"));
        airLifeFlightComboBox->setGeometry(QRect(100, 30, 311, 20));
        airLifeFlightComboBox->setEditable(true);
        airLifeAirplaneUUIDLabel = new QLabel(airLifeFlightGroupBox);
        airLifeAirplaneUUIDLabel->setObjectName(QString::fromUtf8("airLifeAirplaneUUIDLabel"));
        airLifeAirplaneUUIDLabel->setGeometry(QRect(42, 70, 72, 19));
        airLifeAirplaneUUIDComboBox = new QComboBox(airLifeFlightGroupBox);
        airLifeAirplaneUUIDComboBox->setObjectName(QString::fromUtf8("airLifeAirplaneUUIDComboBox"));
        airLifeAirplaneUUIDComboBox->setGeometry(QRect(100, 70, 311, 20));
        airLifeAddNewFlightPushButton = new QPushButton(airLifeFlightGroupBox);
        airLifeAddNewFlightPushButton->setObjectName(QString::fromUtf8("airLifeAddNewFlightPushButton"));
        airLifeAddNewFlightPushButton->setGeometry(QRect(290, 210, 141, 61));
        verticalLayoutWidget = new QWidget(airLifeFlightGroupBox);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 90, 371, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        airLifeSELabel = new QLabel(verticalLayoutWidget);
        airLifeSELabel->setObjectName(QString::fromUtf8("airLifeSELabel"));

        horizontalLayout_2->addWidget(airLifeSELabel);

        airLifeEComboBox = new QComboBox(verticalLayoutWidget);
        airLifeEComboBox->setObjectName(QString::fromUtf8("airLifeEComboBox"));
        airLifeEComboBox->setEditable(true);

        horizontalLayout_2->addWidget(airLifeEComboBox);

        airLifeArrowLabel = new QLabel(verticalLayoutWidget);
        airLifeArrowLabel->setObjectName(QString::fromUtf8("airLifeArrowLabel"));
        airLifeArrowLabel->setFocusPolicy(Qt::NoFocus);
        airLifeArrowLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(airLifeArrowLabel);

        airLifeSComboBox = new QComboBox(verticalLayoutWidget);
        airLifeSComboBox->setObjectName(QString::fromUtf8("airLifeSComboBox"));
        airLifeSComboBox->setEditable(true);

        horizontalLayout_2->addWidget(airLifeSComboBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        airLifeSTimeELabel = new QLabel(verticalLayoutWidget);
        airLifeSTimeELabel->setObjectName(QString::fromUtf8("airLifeSTimeELabel"));

        horizontalLayout_3->addWidget(airLifeSTimeELabel);

        airLifeTimeLineEdit = new QLineEdit(verticalLayoutWidget);
        airLifeTimeLineEdit->setObjectName(QString::fromUtf8("airLifeTimeLineEdit"));
        airLifeTimeLineEdit->setReadOnly(false);

        horizontalLayout_3->addWidget(airLifeTimeLineEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        airLifeBackPushButton = new QPushButton(airLifeWidget__informationLoggerWidget);
        airLifeBackPushButton->setObjectName(QString::fromUtf8("airLifeBackPushButton"));
        airLifeBackPushButton->setGeometry(QRect(710, 330, 111, 51));

        retranslateUi(airLifeWidget__informationLoggerWidget);

        QMetaObject::connectSlotsByName(airLifeWidget__informationLoggerWidget);
    } // setupUi

    void retranslateUi(QWidget *airLifeWidget__informationLoggerWidget)
    {
        airLifeWidget__informationLoggerWidget->setWindowTitle(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\345\275\225\345\205\245\344\277\241\346\201\257", nullptr));
        airLifeBaseGroupBox->setTitle(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\345\237\272\347\241\200\344\277\241\346\201\257\346\226\260\345\242\236", nullptr));
        airLifeAddNewAirplaneGroupBox->setTitle(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\346\226\260\351\243\236\346\234\272", nullptr));
        airLifeAddNewAirplanePushButton->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\346\267\273\345\212\240", nullptr));
        airLifeAddNewAirplaneUUIDLabel->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\346\226\260\351\243\236\346\234\272\347\274\226\345\217\267\357\274\232", nullptr));
        airLifeAddNewAirplaneCapLineLabel->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\345\256\242\350\275\275\351\207\217\357\274\232", nullptr));
        airLifeAddNewAreasLabel->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\346\226\260\345\234\260\347\202\271\357\274\232", nullptr));
        airLifeAddNewAreasPushButton->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\346\267\273\345\212\240", nullptr));
        airLifeFlightGroupBox->setTitle(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\350\210\252\347\217\255\344\277\241\346\201\257\346\226\260\345\242\236", nullptr));
        airLifeFlightLabel->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\350\210\252\347\217\255\347\274\226\345\217\267\357\274\232", nullptr));
        airLifeAirplaneUUIDLabel->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\351\243\236\346\234\272\347\274\226\345\217\267\357\274\232", nullptr));
        airLifeAddNewFlightPushButton->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\346\267\273\345\212\240\350\210\252\347\217\255", nullptr));
        airLifeSELabel->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\350\265\267\347\202\271/\347\273\210\347\202\271\357\274\232", nullptr));
        airLifeArrowLabel->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "--->", nullptr));
        airLifeSTimeELabel->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\345\217\221\347\217\255\346\227\266\345\210\273\357\274\232", nullptr));
        airLifeBackPushButton->setText(QCoreApplication::translate("airLifeWidget::informationLoggerWidget", "\350\277\224\345\233\236(&R)", nullptr));
    } // retranslateUi

};

} // namespace airLifeWidget

namespace airLifeWidget {
namespace Ui {
    class informationLoggerWidget: public Ui_informationLoggerWidget {};
} // namespace Ui
} // namespace airLifeWidget

#endif // UI_INFORMATIONLOGGERWIDGET_H

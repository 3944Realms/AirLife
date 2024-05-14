/********************************************************************************
** Form generated from reading UI file 'informationmodifierwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONMODIFIERWIDGET_H
#define UI_INFORMATIONMODIFIERWIDGET_H

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

class Ui_informationModifierWidget
{
public:
    QGroupBox *airLifeFlightGroupBox;
    QLabel *airLifeFlightLabel;
    QComboBox *airLifeFlightComboBox;
    QLabel *airLifeAirplaneUUIDLabel;
    QComboBox *airLifeAirplaneUUIDComboBox;
    QPushButton *airLifeModifyFlightPushButton;
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
    QPushButton *airLifeDeleteFlightPushButton;
    QGroupBox *airLifeBaseGroupBox;
    QGroupBox *airLifeAddNewAirplaneGroupBox;
    QPushButton *airLifeModifyAirplanePushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *airLifeThisAirplaneUUIDLabel;
    QLabel *airLifeUpdateAirplaneCapLineLabel;
    QLineEdit *airLifeUpdateAirplaneCapLineEdit;
    QComboBox *airLifeThisAirplaneUUIDComboBox;
    QPushButton *airLifeDeleteAirplanePushButton_2;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QComboBox *airLifeThisAreaComboBox;
    QLabel *airLifeThisAreaLabel;
    QLineEdit *airLifeThisAreaNewNameLineEdit;
    QLabel *airLifeThisAreaNewNameLabel;
    QPushButton *airLifeModifyAreasPushButton;
    QPushButton *airLifeDeleteAreaPushButton;
    QPushButton *airLifeBackPushButton;

    void setupUi(QWidget *airLifeWidget__informationModifierWidget)
    {
        if (airLifeWidget__informationModifierWidget->objectName().isEmpty())
            airLifeWidget__informationModifierWidget->setObjectName(QString::fromUtf8("airLifeWidget__informationModifierWidget"));
        airLifeWidget__informationModifierWidget->resize(835, 483);
        airLifeWidget__informationModifierWidget->setMinimumSize(QSize(835, 483));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeWidget__informationModifierWidget->setWindowIcon(icon);
        airLifeFlightGroupBox = new QGroupBox(airLifeWidget__informationModifierWidget);
        airLifeFlightGroupBox->setObjectName(QString::fromUtf8("airLifeFlightGroupBox"));
        airLifeFlightGroupBox->setGeometry(QRect(370, 10, 441, 281));
        airLifeFlightLabel = new QLabel(airLifeFlightGroupBox);
        airLifeFlightLabel->setObjectName(QString::fromUtf8("airLifeFlightLabel"));
        airLifeFlightLabel->setGeometry(QRect(10, 20, 91, 41));
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
        airLifeModifyFlightPushButton = new QPushButton(airLifeFlightGroupBox);
        airLifeModifyFlightPushButton->setObjectName(QString::fromUtf8("airLifeModifyFlightPushButton"));
        airLifeModifyFlightPushButton->setGeometry(QRect(140, 200, 141, 61));
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

        airLifeDeleteFlightPushButton = new QPushButton(airLifeFlightGroupBox);
        airLifeDeleteFlightPushButton->setObjectName(QString::fromUtf8("airLifeDeleteFlightPushButton"));
        airLifeDeleteFlightPushButton->setGeometry(QRect(400, 240, 41, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Simon/SymbolsDeleteSi.png"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeDeleteFlightPushButton->setIcon(icon1);
        airLifeBaseGroupBox = new QGroupBox(airLifeWidget__informationModifierWidget);
        airLifeBaseGroupBox->setObjectName(QString::fromUtf8("airLifeBaseGroupBox"));
        airLifeBaseGroupBox->setGeometry(QRect(0, 10, 351, 461));
        airLifeAddNewAirplaneGroupBox = new QGroupBox(airLifeBaseGroupBox);
        airLifeAddNewAirplaneGroupBox->setObjectName(QString::fromUtf8("airLifeAddNewAirplaneGroupBox"));
        airLifeAddNewAirplaneGroupBox->setGeometry(QRect(30, 230, 301, 171));
        airLifeModifyAirplanePushButton = new QPushButton(airLifeAddNewAirplaneGroupBox);
        airLifeModifyAirplanePushButton->setObjectName(QString::fromUtf8("airLifeModifyAirplanePushButton"));
        airLifeModifyAirplanePushButton->setGeometry(QRect(110, 120, 75, 23));
        gridLayoutWidget = new QWidget(airLifeAddNewAirplaneGroupBox);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 30, 241, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        airLifeThisAirplaneUUIDLabel = new QLabel(gridLayoutWidget);
        airLifeThisAirplaneUUIDLabel->setObjectName(QString::fromUtf8("airLifeThisAirplaneUUIDLabel"));

        gridLayout->addWidget(airLifeThisAirplaneUUIDLabel, 0, 0, 1, 1);

        airLifeUpdateAirplaneCapLineLabel = new QLabel(gridLayoutWidget);
        airLifeUpdateAirplaneCapLineLabel->setObjectName(QString::fromUtf8("airLifeUpdateAirplaneCapLineLabel"));

        gridLayout->addWidget(airLifeUpdateAirplaneCapLineLabel, 1, 0, 1, 1);

        airLifeUpdateAirplaneCapLineEdit = new QLineEdit(gridLayoutWidget);
        airLifeUpdateAirplaneCapLineEdit->setObjectName(QString::fromUtf8("airLifeUpdateAirplaneCapLineEdit"));

        gridLayout->addWidget(airLifeUpdateAirplaneCapLineEdit, 1, 1, 1, 1);

        airLifeThisAirplaneUUIDComboBox = new QComboBox(gridLayoutWidget);
        airLifeThisAirplaneUUIDComboBox->setObjectName(QString::fromUtf8("airLifeThisAirplaneUUIDComboBox"));
        airLifeThisAirplaneUUIDComboBox->setEditable(true);

        gridLayout->addWidget(airLifeThisAirplaneUUIDComboBox, 0, 1, 1, 1);

        airLifeDeleteAirplanePushButton_2 = new QPushButton(airLifeAddNewAirplaneGroupBox);
        airLifeDeleteAirplanePushButton_2->setObjectName(QString::fromUtf8("airLifeDeleteAirplanePushButton_2"));
        airLifeDeleteAirplanePushButton_2->setGeometry(QRect(260, 130, 41, 41));
        airLifeDeleteAirplanePushButton_2->setIcon(icon1);
        groupBox = new QGroupBox(airLifeBaseGroupBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 301, 171));
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 30, 241, 80));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        airLifeThisAreaComboBox = new QComboBox(gridLayoutWidget_2);
        airLifeThisAreaComboBox->setObjectName(QString::fromUtf8("airLifeThisAreaComboBox"));

        gridLayout_2->addWidget(airLifeThisAreaComboBox, 0, 1, 1, 1);

        airLifeThisAreaLabel = new QLabel(gridLayoutWidget_2);
        airLifeThisAreaLabel->setObjectName(QString::fromUtf8("airLifeThisAreaLabel"));

        gridLayout_2->addWidget(airLifeThisAreaLabel, 0, 0, 1, 1);

        airLifeThisAreaNewNameLineEdit = new QLineEdit(gridLayoutWidget_2);
        airLifeThisAreaNewNameLineEdit->setObjectName(QString::fromUtf8("airLifeThisAreaNewNameLineEdit"));

        gridLayout_2->addWidget(airLifeThisAreaNewNameLineEdit, 1, 1, 1, 1);

        airLifeThisAreaNewNameLabel = new QLabel(gridLayoutWidget_2);
        airLifeThisAreaNewNameLabel->setObjectName(QString::fromUtf8("airLifeThisAreaNewNameLabel"));
        airLifeThisAreaNewNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(airLifeThisAreaNewNameLabel, 1, 0, 1, 1);

        airLifeModifyAreasPushButton = new QPushButton(groupBox);
        airLifeModifyAreasPushButton->setObjectName(QString::fromUtf8("airLifeModifyAreasPushButton"));
        airLifeModifyAreasPushButton->setGeometry(QRect(110, 120, 75, 23));
        airLifeDeleteAreaPushButton = new QPushButton(groupBox);
        airLifeDeleteAreaPushButton->setObjectName(QString::fromUtf8("airLifeDeleteAreaPushButton"));
        airLifeDeleteAreaPushButton->setGeometry(QRect(260, 130, 41, 41));
        airLifeDeleteAreaPushButton->setIcon(icon1);
        airLifeBackPushButton = new QPushButton(airLifeWidget__informationModifierWidget);
        airLifeBackPushButton->setObjectName(QString::fromUtf8("airLifeBackPushButton"));
        airLifeBackPushButton->setGeometry(QRect(690, 360, 111, 51));

        retranslateUi(airLifeWidget__informationModifierWidget);

        QMetaObject::connectSlotsByName(airLifeWidget__informationModifierWidget);
    } // setupUi

    void retranslateUi(QWidget *airLifeWidget__informationModifierWidget)
    {
        airLifeWidget__informationModifierWidget->setWindowTitle(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\344\277\241\346\201\257\345\210\240\346\224\271", nullptr));
        airLifeFlightGroupBox->setTitle(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\350\210\252\347\217\255\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        airLifeFlightLabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\350\210\252\347\217\255\347\274\226\345\217\267\357\274\232", nullptr));
        airLifeAirplaneUUIDLabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\351\243\236\346\234\272\347\274\226\345\217\267\357\274\232", nullptr));
        airLifeModifyFlightPushButton->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\344\277\256\346\224\271\350\210\252\347\217\255", nullptr));
        airLifeSELabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\350\265\267\347\202\271/\347\273\210\347\202\271\357\274\232", nullptr));
        airLifeArrowLabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "--->", nullptr));
        airLifeSTimeELabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\345\217\221\347\217\255\346\227\266\345\210\273\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        airLifeDeleteFlightPushButton->setToolTip(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\345\210\240\351\231\244\350\257\245\350\210\252\347\217\255\345\256\236\344\276\213", nullptr));
#endif // QT_CONFIG(tooltip)
        airLifeDeleteFlightPushButton->setText(QString());
        airLifeBaseGroupBox->setTitle(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\345\237\272\347\241\200\344\277\241\346\201\257\344\277\256\346\224\271", nullptr));
        airLifeAddNewAirplaneGroupBox->setTitle(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\351\243\236\346\234\272\344\277\256\346\224\271", nullptr));
        airLifeModifyAirplanePushButton->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\344\277\256\346\224\271", nullptr));
        airLifeThisAirplaneUUIDLabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\344\277\256\346\224\271\351\243\236\346\234\272\347\274\226\345\217\267\357\274\232", nullptr));
        airLifeUpdateAirplaneCapLineLabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\344\277\256\346\224\271\345\256\242\350\275\275\351\207\217\357\274\232", nullptr));
#if QT_CONFIG(tooltip)
        airLifeDeleteAirplanePushButton_2->setToolTip(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\350\213\245\346\227\240\350\210\252\347\217\255\345\274\225\347\224\250\357\274\214\345\210\231\345\210\240\351\231\244\350\257\245\351\243\236\346\234\272\345\256\236\344\276\213", nullptr));
#endif // QT_CONFIG(tooltip)
        airLifeDeleteAirplanePushButton_2->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\345\234\260\347\202\271\344\277\256\346\224\271", nullptr));
        airLifeThisAreaLabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\344\277\256\346\224\271\345\234\260\347\202\271\357\274\232", nullptr));
        airLifeThisAreaNewNameLabel->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\344\277\256\346\224\271\344\270\272\357\274\232", nullptr));
        airLifeModifyAreasPushButton->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\344\277\256\346\224\271", nullptr));
#if QT_CONFIG(tooltip)
        airLifeDeleteAreaPushButton->setToolTip(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\350\213\245\346\227\240\350\210\252\347\217\255\345\274\225\347\224\250\357\274\214\345\210\231\345\210\240\351\231\244\350\257\245\345\234\260\347\202\271\345\256\236\344\276\213", nullptr));
#endif // QT_CONFIG(tooltip)
        airLifeDeleteAreaPushButton->setText(QString());
        airLifeBackPushButton->setText(QCoreApplication::translate("airLifeWidget::informationModifierWidget", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

} // namespace airLifeWidget

namespace airLifeWidget {
namespace Ui {
    class informationModifierWidget: public Ui_informationModifierWidget {};
} // namespace Ui
} // namespace airLifeWidget

#endif // UI_INFORMATIONMODIFIERWIDGET_H

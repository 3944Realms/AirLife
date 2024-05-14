/********************************************************************************
** Form generated from reading UI file 'informationfinderwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMATIONFINDERWIDGET_H
#define UI_INFORMATIONFINDERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace airLifeWidget {

class Ui_informationFinderWidget
{
public:
    QComboBox *airLifeFlightComboBox;
    QLabel *airLifeFlightLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *airLifeSELabel;
    QComboBox *airLifeSComboBox;
    QLabel *airLifeArrowLabel;
    QComboBox *airLifeEComboBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *airLifeSTimeELabel;
    QLineEdit *airLifeTimeLineEdit;
    QPushButton *airLifeBeginPushButton;
    QPushButton *airLifeBackPushButton;
    QGroupBox *airLifeModeGroupBox;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *airLifeSearchByFlightRadioButton;
    QRadioButton *airLifeSearchByAreaRadioButton;
    QRadioButton *airLifeSearchByDatetRadioButton;

    void setupUi(QWidget *airLifeWidget__informationFinderWidget)
    {
        if (airLifeWidget__informationFinderWidget->objectName().isEmpty())
            airLifeWidget__informationFinderWidget->setObjectName(QString::fromUtf8("airLifeWidget__informationFinderWidget"));
        airLifeWidget__informationFinderWidget->resize(400, 300);
        airLifeWidget__informationFinderWidget->setMinimumSize(QSize(400, 300));
        airLifeWidget__informationFinderWidget->setMaximumSize(QSize(400, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeWidget__informationFinderWidget->setWindowIcon(icon);
        airLifeFlightComboBox = new QComboBox(airLifeWidget__informationFinderWidget);
        airLifeFlightComboBox->setObjectName(QString::fromUtf8("airLifeFlightComboBox"));
        airLifeFlightComboBox->setGeometry(QRect(50, 10, 331, 19));
        airLifeFlightComboBox->setEditable(true);
        airLifeFlightLabel = new QLabel(airLifeWidget__informationFinderWidget);
        airLifeFlightLabel->setObjectName(QString::fromUtf8("airLifeFlightLabel"));
        airLifeFlightLabel->setGeometry(QRect(10, 0, 51, 41));
        airLifeFlightLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayoutWidget = new QWidget(airLifeWidget__informationFinderWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 40, 371, 101));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        airLifeSELabel = new QLabel(verticalLayoutWidget);
        airLifeSELabel->setObjectName(QString::fromUtf8("airLifeSELabel"));

        horizontalLayout->addWidget(airLifeSELabel);

        airLifeSComboBox = new QComboBox(verticalLayoutWidget);
        airLifeSComboBox->setObjectName(QString::fromUtf8("airLifeSComboBox"));

        horizontalLayout->addWidget(airLifeSComboBox);

        airLifeArrowLabel = new QLabel(verticalLayoutWidget);
        airLifeArrowLabel->setObjectName(QString::fromUtf8("airLifeArrowLabel"));
        airLifeArrowLabel->setContextMenuPolicy(Qt::CustomContextMenu);
        airLifeArrowLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(airLifeArrowLabel);

        airLifeEComboBox = new QComboBox(verticalLayoutWidget);
        airLifeEComboBox->setObjectName(QString::fromUtf8("airLifeEComboBox"));

        horizontalLayout->addWidget(airLifeEComboBox);


        verticalLayout->addLayout(horizontalLayout);

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

        airLifeBeginPushButton = new QPushButton(airLifeWidget__informationFinderWidget);
        airLifeBeginPushButton->setObjectName(QString::fromUtf8("airLifeBeginPushButton"));
        airLifeBeginPushButton->setGeometry(QRect(240, 170, 111, 51));
        airLifeBackPushButton = new QPushButton(airLifeWidget__informationFinderWidget);
        airLifeBackPushButton->setObjectName(QString::fromUtf8("airLifeBackPushButton"));
        airLifeBackPushButton->setGeometry(QRect(240, 230, 111, 51));
        airLifeModeGroupBox = new QGroupBox(airLifeWidget__informationFinderWidget);
        airLifeModeGroupBox->setObjectName(QString::fromUtf8("airLifeModeGroupBox"));
        airLifeModeGroupBox->setGeometry(QRect(20, 160, 201, 131));
        verticalLayoutWidget_2 = new QWidget(airLifeModeGroupBox);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 160, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        airLifeSearchByFlightRadioButton = new QRadioButton(verticalLayoutWidget_2);
        airLifeSearchByFlightRadioButton->setObjectName(QString::fromUtf8("airLifeSearchByFlightRadioButton"));

        verticalLayout_2->addWidget(airLifeSearchByFlightRadioButton);

        airLifeSearchByAreaRadioButton = new QRadioButton(verticalLayoutWidget_2);
        airLifeSearchByAreaRadioButton->setObjectName(QString::fromUtf8("airLifeSearchByAreaRadioButton"));

        verticalLayout_2->addWidget(airLifeSearchByAreaRadioButton);

        airLifeSearchByDatetRadioButton = new QRadioButton(verticalLayoutWidget_2);
        airLifeSearchByDatetRadioButton->setObjectName(QString::fromUtf8("airLifeSearchByDatetRadioButton"));

        verticalLayout_2->addWidget(airLifeSearchByDatetRadioButton);


        retranslateUi(airLifeWidget__informationFinderWidget);

        QMetaObject::connectSlotsByName(airLifeWidget__informationFinderWidget);
    } // setupUi

    void retranslateUi(QWidget *airLifeWidget__informationFinderWidget)
    {
        airLifeWidget__informationFinderWidget->setWindowTitle(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\346\237\245\350\257\242\344\277\241\346\201\257", nullptr));
        airLifeFlightLabel->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\350\210\252\347\217\255\357\274\232", nullptr));
        airLifeSELabel->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\350\265\267\347\202\271/\347\273\210\347\202\271\357\274\232", nullptr));
        airLifeArrowLabel->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "--->", nullptr));
        airLifeSTimeELabel->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\345\217\221\347\217\255\346\227\266\345\210\273\357\274\232", nullptr));
        airLifeBeginPushButton->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\346\237\245\350\257\242(&S)", nullptr));
        airLifeBackPushButton->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\350\277\224\345\233\236(&R)", nullptr));
        airLifeModeGroupBox->setTitle(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\346\237\245\350\257\242\346\250\241\345\274\217", nullptr));
        airLifeSearchByFlightRadioButton->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\351\200\232\350\277\207\350\210\252\347\217\255\346\237\245\350\257\242(&A)", nullptr));
        airLifeSearchByAreaRadioButton->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\351\200\232\350\277\207\350\265\267\347\202\271\346\210\226\347\273\210\347\202\271\346\237\245\350\257\242(&B)", nullptr));
        airLifeSearchByDatetRadioButton->setText(QCoreApplication::translate("airLifeWidget::informationFinderWidget", "\351\200\232\350\277\207\345\217\221\347\217\255\346\227\266\345\210\273\346\237\245\350\257\242(&C)", nullptr));
    } // retranslateUi

};

} // namespace airLifeWidget

namespace airLifeWidget {
namespace Ui {
    class informationFinderWidget: public Ui_informationFinderWidget {};
} // namespace Ui
} // namespace airLifeWidget

#endif // UI_INFORMATIONFINDERWIDGET_H

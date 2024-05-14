/********************************************************************************
** Form generated from reading UI file 'orderdestroyerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERDESTROYERWIDGET_H
#define UI_ORDERDESTROYERWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace airLifeWidget {

class Ui_orderDestroyerWidget
{
public:
    QLabel *airLifeFlightLabel;
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
    QLineEdit *airLifeOrderUUIDLineEdit;
    QLabel *airLifeOrderUUIDLabel;
    QLineEdit *airLifeFlightLineEdit;
    QPushButton *pushButton;
    QPushButton *airLifeBackPushButton;
    QPushButton *airLifeChargebackPushButton;
    QLineEdit *airLifeChargebackStatusLineEdit;
    QLabel *airLifeChargebackStatusLabel;

    void setupUi(QWidget *airLifeWidget__orderDestroyerWidget)
    {
        if (airLifeWidget__orderDestroyerWidget->objectName().isEmpty())
            airLifeWidget__orderDestroyerWidget->setObjectName(QString::fromUtf8("airLifeWidget__orderDestroyerWidget"));
        airLifeWidget__orderDestroyerWidget->resize(400, 300);
        airLifeWidget__orderDestroyerWidget->setMinimumSize(QSize(400, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeWidget__orderDestroyerWidget->setWindowIcon(icon);
        airLifeFlightLabel = new QLabel(airLifeWidget__orderDestroyerWidget);
        airLifeFlightLabel->setObjectName(QString::fromUtf8("airLifeFlightLabel"));
        airLifeFlightLabel->setGeometry(QRect(10, 50, 51, 41));
        airLifeFlightLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayoutWidget = new QWidget(airLifeWidget__orderDestroyerWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 90, 371, 101));
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

        airLifeOrderUUIDLineEdit = new QLineEdit(airLifeWidget__orderDestroyerWidget);
        airLifeOrderUUIDLineEdit->setObjectName(QString::fromUtf8("airLifeOrderUUIDLineEdit"));
        airLifeOrderUUIDLineEdit->setGeometry(QRect(70, 20, 141, 20));
        airLifeOrderUUIDLabel = new QLabel(airLifeWidget__orderDestroyerWidget);
        airLifeOrderUUIDLabel->setObjectName(QString::fromUtf8("airLifeOrderUUIDLabel"));
        airLifeOrderUUIDLabel->setGeometry(QRect(10, 10, 60, 44));
        airLifeFlightLineEdit = new QLineEdit(airLifeWidget__orderDestroyerWidget);
        airLifeFlightLineEdit->setObjectName(QString::fromUtf8("airLifeFlightLineEdit"));
        airLifeFlightLineEdit->setGeometry(QRect(50, 60, 331, 19));
        pushButton = new QPushButton(airLifeWidget__orderDestroyerWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 20, 101, 23));
        airLifeBackPushButton = new QPushButton(airLifeWidget__orderDestroyerWidget);
        airLifeBackPushButton->setObjectName(QString::fromUtf8("airLifeBackPushButton"));
        airLifeBackPushButton->setGeometry(QRect(280, 240, 111, 51));
        airLifeChargebackPushButton = new QPushButton(airLifeWidget__orderDestroyerWidget);
        airLifeChargebackPushButton->setObjectName(QString::fromUtf8("airLifeChargebackPushButton"));
        airLifeChargebackPushButton->setGeometry(QRect(20, 240, 111, 51));
        airLifeChargebackStatusLineEdit = new QLineEdit(airLifeWidget__orderDestroyerWidget);
        airLifeChargebackStatusLineEdit->setObjectName(QString::fromUtf8("airLifeChargebackStatusLineEdit"));
        airLifeChargebackStatusLineEdit->setGeometry(QRect(80, 200, 141, 20));
        airLifeChargebackStatusLineEdit->setReadOnly(true);
        airLifeChargebackStatusLabel = new QLabel(airLifeWidget__orderDestroyerWidget);
        airLifeChargebackStatusLabel->setObjectName(QString::fromUtf8("airLifeChargebackStatusLabel"));
        airLifeChargebackStatusLabel->setGeometry(QRect(10, 190, 60, 44));

        retranslateUi(airLifeWidget__orderDestroyerWidget);

        QMetaObject::connectSlotsByName(airLifeWidget__orderDestroyerWidget);
    } // setupUi

    void retranslateUi(QWidget *airLifeWidget__orderDestroyerWidget)
    {
        airLifeWidget__orderDestroyerWidget->setWindowTitle(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\351\200\200\345\215\225", nullptr));
        airLifeFlightLabel->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\350\210\252\347\217\255\357\274\232", nullptr));
        airLifeSELabel->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\350\265\267\347\202\271/\347\273\210\347\202\271\357\274\232", nullptr));
        airLifeArrowLabel->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "--->", nullptr));
        airLifeSTimeELabel->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\345\217\221\347\217\255\346\227\266\345\210\273\357\274\232", nullptr));
        airLifeOrderUUIDLabel->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\350\256\242\345\215\225\347\274\226\345\217\267\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\350\216\267\345\217\226\350\256\242\345\215\225\344\277\241\346\201\257(&G)", nullptr));
        airLifeBackPushButton->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\350\277\224\345\233\236(&R)", nullptr));
        airLifeChargebackPushButton->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\351\200\200\345\215\225(&D)", nullptr));
        airLifeChargebackStatusLineEdit->setText(QString());
        airLifeChargebackStatusLabel->setText(QCoreApplication::translate("airLifeWidget::orderDestroyerWidget", "\351\200\200\345\215\225\347\212\266\346\200\201\357\274\232", nullptr));
    } // retranslateUi

};

} // namespace airLifeWidget

namespace airLifeWidget {
namespace Ui {
    class orderDestroyerWidget: public Ui_orderDestroyerWidget {};
} // namespace Ui
} // namespace airLifeWidget

#endif // UI_ORDERDESTROYERWIDGET_H

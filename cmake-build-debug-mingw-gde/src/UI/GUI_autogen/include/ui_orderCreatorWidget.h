/********************************************************************************
** Form generated from reading UI file 'ordercreatorwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERCREATORWIDGET_H
#define UI_ORDERCREATORWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

namespace airLifeWidget {

class Ui_orderCreatorWidget
{
public:
    QComboBox *airLifeFlightComboBox;
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
    QPushButton *airLifeCreatePushButton;
    QPushButton *airLifeBackPushButton;
    QLineEdit *airLifeOrderUUIDLineEdit;
    QLabel *airLifeOrderUUIDLabel;
    QLabel *airLifeOrderStatusLabel;
    QLineEdit *airLifeOrderStatusLineEdit;

    void setupUi(QWidget *airLifeWidget__orderCreatorWidget)
    {
        if (airLifeWidget__orderCreatorWidget->objectName().isEmpty())
            airLifeWidget__orderCreatorWidget->setObjectName(QString::fromUtf8("airLifeWidget__orderCreatorWidget"));
        airLifeWidget__orderCreatorWidget->resize(400, 300);
        airLifeWidget__orderCreatorWidget->setMinimumSize(QSize(400, 300));
        airLifeWidget__orderCreatorWidget->setMaximumSize(QSize(400, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeWidget__orderCreatorWidget->setWindowIcon(icon);
        airLifeFlightComboBox = new QComboBox(airLifeWidget__orderCreatorWidget);
        airLifeFlightComboBox->setObjectName(QString::fromUtf8("airLifeFlightComboBox"));
        airLifeFlightComboBox->setGeometry(QRect(50, 30, 331, 19));
        airLifeFlightComboBox->setEditable(true);
        airLifeFlightLabel = new QLabel(airLifeWidget__orderCreatorWidget);
        airLifeFlightLabel->setObjectName(QString::fromUtf8("airLifeFlightLabel"));
        airLifeFlightLabel->setGeometry(QRect(10, 20, 51, 41));
        airLifeFlightLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        verticalLayoutWidget = new QWidget(airLifeWidget__orderCreatorWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 60, 371, 101));
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

        airLifeCreatePushButton = new QPushButton(airLifeWidget__orderCreatorWidget);
        airLifeCreatePushButton->setObjectName(QString::fromUtf8("airLifeCreatePushButton"));
        airLifeCreatePushButton->setGeometry(QRect(30, 180, 111, 51));
        airLifeBackPushButton = new QPushButton(airLifeWidget__orderCreatorWidget);
        airLifeBackPushButton->setObjectName(QString::fromUtf8("airLifeBackPushButton"));
        airLifeBackPushButton->setGeometry(QRect(30, 240, 111, 51));
        airLifeOrderUUIDLineEdit = new QLineEdit(airLifeWidget__orderCreatorWidget);
        airLifeOrderUUIDLineEdit->setObjectName(QString::fromUtf8("airLifeOrderUUIDLineEdit"));
        airLifeOrderUUIDLineEdit->setGeometry(QRect(230, 190, 141, 20));
        airLifeOrderUUIDLineEdit->setReadOnly(true);
        airLifeOrderUUIDLabel = new QLabel(airLifeWidget__orderCreatorWidget);
        airLifeOrderUUIDLabel->setObjectName(QString::fromUtf8("airLifeOrderUUIDLabel"));
        airLifeOrderUUIDLabel->setGeometry(QRect(160, 180, 60, 44));
        airLifeOrderStatusLabel = new QLabel(airLifeWidget__orderCreatorWidget);
        airLifeOrderStatusLabel->setObjectName(QString::fromUtf8("airLifeOrderStatusLabel"));
        airLifeOrderStatusLabel->setGeometry(QRect(160, 220, 60, 44));
        airLifeOrderStatusLineEdit = new QLineEdit(airLifeWidget__orderCreatorWidget);
        airLifeOrderStatusLineEdit->setObjectName(QString::fromUtf8("airLifeOrderStatusLineEdit"));
        airLifeOrderStatusLineEdit->setGeometry(QRect(230, 230, 141, 20));
        airLifeOrderStatusLineEdit->setReadOnly(true);

        retranslateUi(airLifeWidget__orderCreatorWidget);

        QMetaObject::connectSlotsByName(airLifeWidget__orderCreatorWidget);
    } // setupUi

    void retranslateUi(QWidget *airLifeWidget__orderCreatorWidget)
    {
        airLifeWidget__orderCreatorWidget->setWindowTitle(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "\345\210\233\345\273\272\350\256\242\345\215\225", nullptr));
        airLifeFlightLabel->setText(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "\350\210\252\347\217\255\357\274\232", nullptr));
        airLifeSELabel->setText(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "\350\265\267\347\202\271/\347\273\210\347\202\271\357\274\232", nullptr));
        airLifeArrowLabel->setText(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "--->", nullptr));
        airLifeSTimeELabel->setText(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "\345\217\221\347\217\255\346\227\266\345\210\273\357\274\232", nullptr));
        airLifeCreatePushButton->setText(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "\345\210\233\345\273\272", nullptr));
        airLifeBackPushButton->setText(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "\350\277\224\345\233\236", nullptr));
        airLifeOrderUUIDLabel->setText(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "\350\256\242\345\215\225\347\274\226\345\217\267\357\274\232", nullptr));
        airLifeOrderStatusLabel->setText(QCoreApplication::translate("airLifeWidget::orderCreatorWidget", "\350\256\242\345\215\225\347\212\266\346\200\201\357\274\232", nullptr));
    } // retranslateUi

};

} // namespace airLifeWidget

namespace airLifeWidget {
namespace Ui {
    class orderCreatorWidget: public Ui_orderCreatorWidget {};
} // namespace Ui
} // namespace airLifeWidget

#endif // UI_ORDERCREATORWIDGET_H

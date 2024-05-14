/********************************************************************************
** Form generated from reading UI file 'airlifemaingui.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AIRLIFEMAINGUI_H
#define UI_AIRLIFEMAINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

namespace airLifeGui {

class Ui_AirLifeMainGUI
{
public:
    QAction *actiond;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menubianj;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *airLifeGui__AirLifeMainGUI)
    {
        if (airLifeGui__AirLifeMainGUI->objectName().isEmpty())
            airLifeGui__AirLifeMainGUI->setObjectName(QString::fromUtf8("airLifeGui__AirLifeMainGUI"));
        airLifeGui__AirLifeMainGUI->resize(662, 417);
        actiond = new QAction(airLifeGui__AirLifeMainGUI);
        actiond->setObjectName(QString::fromUtf8("actiond"));
        centralwidget = new QWidget(airLifeGui__AirLifeMainGUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        airLifeGui__AirLifeMainGUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(airLifeGui__AirLifeMainGUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 662, 22));
        menubianj = new QMenu(menubar);
        menubianj->setObjectName(QString::fromUtf8("menubianj"));
        airLifeGui__AirLifeMainGUI->setMenuBar(menubar);
        statusbar = new QStatusBar(airLifeGui__AirLifeMainGUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        airLifeGui__AirLifeMainGUI->setStatusBar(statusbar);

        menubar->addAction(menubianj->menuAction());
        menubianj->addAction(actiond);

        retranslateUi(airLifeGui__AirLifeMainGUI);

        QMetaObject::connectSlotsByName(airLifeGui__AirLifeMainGUI);
    } // setupUi

    void retranslateUi(QMainWindow *airLifeGui__AirLifeMainGUI)
    {
        airLifeGui__AirLifeMainGUI->setWindowTitle(QCoreApplication::translate("airLifeGui::AirLifeMainGUI", "AirLifeMainGUI", nullptr));
        actiond->setText(QCoreApplication::translate("airLifeGui::AirLifeMainGUI", "\347\231\273\345\207\272", nullptr));
        menubianj->setTitle(QCoreApplication::translate("airLifeGui::AirLifeMainGUI", "\347\224\250\346\210\267", nullptr));
    } // retranslateUi

};

} // namespace airLifeGui

namespace airLifeGui {
namespace Ui {
    class AirLifeMainGUI: public Ui_AirLifeMainGUI {};
} // namespace Ui
} // namespace airLifeGui

#endif // UI_AIRLIFEMAINGUI_H

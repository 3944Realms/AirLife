/********************************************************************************
** Form generated from reading UI file 'administermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTERMAINWINDOW_H
#define UI_ADMINISTERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

namespace airLifeMainWindow {

class Ui_AdministerMainWindow
{
public:
    QAction *airLifeAddInformationAction;
    QAction *airLifeMRInformationAction;
    QAction *airLifeAccountLogOutAction;
    QAction *airLifeAccountModifyPasswordAction;
    QAction *airLifeSearchFlightAction;
    QAction *airLifeSearchUserAction;
    QAction *airLifeGetMoreHelpAction;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *airLifeUserUUIDLineEdit;
    QLabel *airLifeUserUUIDLabel;
    QGroupBox *airLifeMUGroupBox;
    QPushButton *airLifeAddInformationPushButton;
    QPushButton *airLifeMRInformationPushButton;
    QMenuBar *menubar;
    QMenu *airLifeInformationManagerMenu;
    QMenu *airLifeSearchMenu;
    QMenu *airLifeAccountMenu;
    QMenu *airLifeAccountPasswordAction;
    QMenu *airLifeHelptMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *airLifeMainWindow__AdministerMainWindow)
    {
        if (airLifeMainWindow__AdministerMainWindow->objectName().isEmpty())
            airLifeMainWindow__AdministerMainWindow->setObjectName(QString::fromUtf8("airLifeMainWindow__AdministerMainWindow"));
        airLifeMainWindow__AdministerMainWindow->resize(388, 317);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeMainWindow__AdministerMainWindow->setWindowIcon(icon);
        airLifeAddInformationAction = new QAction(airLifeMainWindow__AdministerMainWindow);
        airLifeAddInformationAction->setObjectName(QString::fromUtf8("airLifeAddInformationAction"));
        airLifeMRInformationAction = new QAction(airLifeMainWindow__AdministerMainWindow);
        airLifeMRInformationAction->setObjectName(QString::fromUtf8("airLifeMRInformationAction"));
        airLifeAccountLogOutAction = new QAction(airLifeMainWindow__AdministerMainWindow);
        airLifeAccountLogOutAction->setObjectName(QString::fromUtf8("airLifeAccountLogOutAction"));
        airLifeAccountModifyPasswordAction = new QAction(airLifeMainWindow__AdministerMainWindow);
        airLifeAccountModifyPasswordAction->setObjectName(QString::fromUtf8("airLifeAccountModifyPasswordAction"));
        airLifeSearchFlightAction = new QAction(airLifeMainWindow__AdministerMainWindow);
        airLifeSearchFlightAction->setObjectName(QString::fromUtf8("airLifeSearchFlightAction"));
        airLifeSearchUserAction = new QAction(airLifeMainWindow__AdministerMainWindow);
        airLifeSearchUserAction->setObjectName(QString::fromUtf8("airLifeSearchUserAction"));
        airLifeGetMoreHelpAction = new QAction(airLifeMainWindow__AdministerMainWindow);
        airLifeGetMoreHelpAction->setObjectName(QString::fromUtf8("airLifeGetMoreHelpAction"));
        centralwidget = new QWidget(airLifeMainWindow__AdministerMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 181, 31));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        airLifeUserUUIDLineEdit = new QLineEdit(gridLayoutWidget);
        airLifeUserUUIDLineEdit->setObjectName(QString::fromUtf8("airLifeUserUUIDLineEdit"));
        airLifeUserUUIDLineEdit->setReadOnly(true);

        gridLayout->addWidget(airLifeUserUUIDLineEdit, 0, 1, 1, 1);

        airLifeUserUUIDLabel = new QLabel(gridLayoutWidget);
        airLifeUserUUIDLabel->setObjectName(QString::fromUtf8("airLifeUserUUIDLabel"));

        gridLayout->addWidget(airLifeUserUUIDLabel, 0, 0, 1, 1);

        airLifeMUGroupBox = new QGroupBox(centralwidget);
        airLifeMUGroupBox->setObjectName(QString::fromUtf8("airLifeMUGroupBox"));
        airLifeMUGroupBox->setGeometry(QRect(220, 20, 141, 251));
        airLifeAddInformationPushButton = new QPushButton(airLifeMUGroupBox);
        airLifeAddInformationPushButton->setObjectName(QString::fromUtf8("airLifeAddInformationPushButton"));
        airLifeAddInformationPushButton->setGeometry(QRect(20, 40, 101, 71));
        airLifeMRInformationPushButton = new QPushButton(airLifeMUGroupBox);
        airLifeMRInformationPushButton->setObjectName(QString::fromUtf8("airLifeMRInformationPushButton"));
        airLifeMRInformationPushButton->setGeometry(QRect(20, 140, 101, 71));
        airLifeMainWindow__AdministerMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(airLifeMainWindow__AdministerMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 388, 22));
        airLifeInformationManagerMenu = new QMenu(menubar);
        airLifeInformationManagerMenu->setObjectName(QString::fromUtf8("airLifeInformationManagerMenu"));
        airLifeSearchMenu = new QMenu(menubar);
        airLifeSearchMenu->setObjectName(QString::fromUtf8("airLifeSearchMenu"));
        airLifeAccountMenu = new QMenu(menubar);
        airLifeAccountMenu->setObjectName(QString::fromUtf8("airLifeAccountMenu"));
        airLifeAccountPasswordAction = new QMenu(airLifeAccountMenu);
        airLifeAccountPasswordAction->setObjectName(QString::fromUtf8("airLifeAccountPasswordAction"));
        airLifeHelptMenu = new QMenu(menubar);
        airLifeHelptMenu->setObjectName(QString::fromUtf8("airLifeHelptMenu"));
        airLifeMainWindow__AdministerMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(airLifeMainWindow__AdministerMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        airLifeMainWindow__AdministerMainWindow->setStatusBar(statusbar);

        menubar->addAction(airLifeInformationManagerMenu->menuAction());
        menubar->addAction(airLifeSearchMenu->menuAction());
        menubar->addAction(airLifeAccountMenu->menuAction());
        menubar->addAction(airLifeHelptMenu->menuAction());
        airLifeInformationManagerMenu->addAction(airLifeAddInformationAction);
        airLifeInformationManagerMenu->addAction(airLifeMRInformationAction);
        airLifeSearchMenu->addAction(airLifeSearchFlightAction);
        airLifeSearchMenu->addAction(airLifeSearchUserAction);
        airLifeAccountMenu->addAction(airLifeAccountPasswordAction->menuAction());
        airLifeAccountMenu->addAction(airLifeAccountLogOutAction);
        airLifeAccountPasswordAction->addAction(airLifeAccountModifyPasswordAction);
        airLifeHelptMenu->addAction(airLifeGetMoreHelpAction);

        retranslateUi(airLifeMainWindow__AdministerMainWindow);

        QMetaObject::connectSlotsByName(airLifeMainWindow__AdministerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *airLifeMainWindow__AdministerMainWindow)
    {
        airLifeMainWindow__AdministerMainWindow->setWindowTitle(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\347\256\241\347\220\206\345\221\230\344\270\273\347\225\214\351\235\242", nullptr));
        airLifeAddInformationAction->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\345\242\236\345\212\240\344\277\241\346\201\257(&A)", nullptr));
        airLifeMRInformationAction->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\344\277\241\346\201\257\345\210\240\346\224\271(&E)", nullptr));
        airLifeAccountLogOutAction->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\347\231\273\345\207\272(&L)", nullptr));
        airLifeAccountModifyPasswordAction->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201(&C)", nullptr));
        airLifeSearchFlightAction->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\350\210\252\347\217\255\344\277\241\346\201\257(&F)", nullptr));
        airLifeSearchUserAction->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\347\224\250\346\210\267\344\277\241\346\201\257(&U)", nullptr));
        airLifeGetMoreHelpAction->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "More(&M)", nullptr));
        airLifeUserUUIDLabel->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\347\256\241\347\220\206\345\221\230UUID\357\274\232", nullptr));
        airLifeMUGroupBox->setTitle(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\345\212\237\350\203\275", nullptr));
        airLifeAddInformationPushButton->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\345\275\225\345\205\245(&P)", nullptr));
        airLifeMRInformationPushButton->setText(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\345\210\240\346\224\271(&U)", nullptr));
        airLifeInformationManagerMenu->setTitle(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\344\277\241\346\201\257\347\256\241\347\220\206(&M)", nullptr));
        airLifeSearchMenu->setTitle(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\346\237\245\350\257\242(&S)", nullptr));
        airLifeAccountMenu->setTitle(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\350\264\246\346\210\267(&A)", nullptr));
        airLifeAccountPasswordAction->setTitle(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\345\257\206\347\240\201\347\256\241\347\220\206(&M)", nullptr));
        airLifeHelptMenu->setTitle(QCoreApplication::translate("airLifeMainWindow::AdministerMainWindow", "\345\270\256\345\212\251(&H)", nullptr));
    } // retranslateUi

};

} // namespace airLifeMainWindow

namespace airLifeMainWindow {
namespace Ui {
    class AdministerMainWindow: public Ui_AdministerMainWindow {};
} // namespace Ui
} // namespace airLifeMainWindow

#endif // UI_ADMINISTERMAINWINDOW_H

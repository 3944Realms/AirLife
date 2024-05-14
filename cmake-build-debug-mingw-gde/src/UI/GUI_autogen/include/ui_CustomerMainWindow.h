/********************************************************************************
** Form generated from reading UI file 'customermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMERMAINWINDOW_H
#define UI_CUSTOMERMAINWINDOW_H

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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

namespace airLifeMainWindow {

class Ui_CustomerMainWindow
{
public:
    QAction *airLifeAccountModifyPasswordAction;
    QAction *airLifeAccountLogOutAction;
    QAction *airLifeCreateOrderAction;
    QAction *airLifeDeleteOrderAction;
    QAction *airLifeSearchFlightAction;
    QAction *airLifeGetMoreHelpAction;
    QAction *actionw;
    QWidget *centralwidget;
    QGroupBox *airLifeMUGroupBox;
    QPushButton *airLifeCreateOrderPushButton;
    QPushButton *airLifeDeleteOrderPushButton;
    QPushButton *airLifeSearchFlightPushButton;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextEdit *airLifeSituationLineEdit;
    QLineEdit *airLifeUUIDLineEdit;
    QLabel *airLifeUserUUIDLabel;
    QLabel *airLifeSituationLabel;
    QLineEdit *airLifeUserNameLineEdit;
    QLabel *airLifeUserNameLabel;
    QMenuBar *airLifeMenuBar;
    QMenu *airLifeAccountMenu;
    QMenu *airLifeAccountAction;
    QMenu *airLifeOrderMenu;
    QMenu *airLifeSearchMenu;
    QMenu *airLifeHelptMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *airLifeMainWindow__CustomerMainWindow)
    {
        if (airLifeMainWindow__CustomerMainWindow->objectName().isEmpty())
            airLifeMainWindow__CustomerMainWindow->setObjectName(QString::fromUtf8("airLifeMainWindow__CustomerMainWindow"));
        airLifeMainWindow__CustomerMainWindow->resize(403, 323);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Logo/airLifeLogo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        airLifeMainWindow__CustomerMainWindow->setWindowIcon(icon);
        airLifeAccountModifyPasswordAction = new QAction(airLifeMainWindow__CustomerMainWindow);
        airLifeAccountModifyPasswordAction->setObjectName(QString::fromUtf8("airLifeAccountModifyPasswordAction"));
        airLifeAccountLogOutAction = new QAction(airLifeMainWindow__CustomerMainWindow);
        airLifeAccountLogOutAction->setObjectName(QString::fromUtf8("airLifeAccountLogOutAction"));
        airLifeCreateOrderAction = new QAction(airLifeMainWindow__CustomerMainWindow);
        airLifeCreateOrderAction->setObjectName(QString::fromUtf8("airLifeCreateOrderAction"));
        airLifeDeleteOrderAction = new QAction(airLifeMainWindow__CustomerMainWindow);
        airLifeDeleteOrderAction->setObjectName(QString::fromUtf8("airLifeDeleteOrderAction"));
        airLifeSearchFlightAction = new QAction(airLifeMainWindow__CustomerMainWindow);
        airLifeSearchFlightAction->setObjectName(QString::fromUtf8("airLifeSearchFlightAction"));
        airLifeGetMoreHelpAction = new QAction(airLifeMainWindow__CustomerMainWindow);
        airLifeGetMoreHelpAction->setObjectName(QString::fromUtf8("airLifeGetMoreHelpAction"));
        actionw = new QAction(airLifeMainWindow__CustomerMainWindow);
        actionw->setObjectName(QString::fromUtf8("actionw"));
        centralwidget = new QWidget(airLifeMainWindow__CustomerMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        airLifeMUGroupBox = new QGroupBox(centralwidget);
        airLifeMUGroupBox->setObjectName(QString::fromUtf8("airLifeMUGroupBox"));
        airLifeMUGroupBox->setGeometry(QRect(230, 20, 141, 251));
        airLifeCreateOrderPushButton = new QPushButton(airLifeMUGroupBox);
        airLifeCreateOrderPushButton->setObjectName(QString::fromUtf8("airLifeCreateOrderPushButton"));
        airLifeCreateOrderPushButton->setGeometry(QRect(20, 20, 101, 71));
        airLifeDeleteOrderPushButton = new QPushButton(airLifeMUGroupBox);
        airLifeDeleteOrderPushButton->setObjectName(QString::fromUtf8("airLifeDeleteOrderPushButton"));
        airLifeDeleteOrderPushButton->setGeometry(QRect(20, 90, 101, 71));
        airLifeSearchFlightPushButton = new QPushButton(airLifeMUGroupBox);
        airLifeSearchFlightPushButton->setObjectName(QString::fromUtf8("airLifeSearchFlightPushButton"));
        airLifeSearchFlightPushButton->setGeometry(QRect(20, 160, 101, 71));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(29, 32, 191, 211));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        airLifeSituationLineEdit = new QTextEdit(gridLayoutWidget);
        airLifeSituationLineEdit->setObjectName(QString::fromUtf8("airLifeSituationLineEdit"));
        airLifeSituationLineEdit->setReadOnly(true);

        gridLayout->addWidget(airLifeSituationLineEdit, 2, 1, 1, 1);

        airLifeUUIDLineEdit = new QLineEdit(gridLayoutWidget);
        airLifeUUIDLineEdit->setObjectName(QString::fromUtf8("airLifeUUIDLineEdit"));
        airLifeUUIDLineEdit->setReadOnly(true);

        gridLayout->addWidget(airLifeUUIDLineEdit, 0, 1, 1, 1);

        airLifeUserUUIDLabel = new QLabel(gridLayoutWidget);
        airLifeUserUUIDLabel->setObjectName(QString::fromUtf8("airLifeUserUUIDLabel"));

        gridLayout->addWidget(airLifeUserUUIDLabel, 0, 0, 1, 1);

        airLifeSituationLabel = new QLabel(gridLayoutWidget);
        airLifeSituationLabel->setObjectName(QString::fromUtf8("airLifeSituationLabel"));

        gridLayout->addWidget(airLifeSituationLabel, 2, 0, 1, 1);

        airLifeUserNameLineEdit = new QLineEdit(gridLayoutWidget);
        airLifeUserNameLineEdit->setObjectName(QString::fromUtf8("airLifeUserNameLineEdit"));
        airLifeUserNameLineEdit->setReadOnly(true);

        gridLayout->addWidget(airLifeUserNameLineEdit, 1, 1, 1, 1);

        airLifeUserNameLabel = new QLabel(gridLayoutWidget);
        airLifeUserNameLabel->setObjectName(QString::fromUtf8("airLifeUserNameLabel"));

        gridLayout->addWidget(airLifeUserNameLabel, 1, 0, 1, 1);

        airLifeMainWindow__CustomerMainWindow->setCentralWidget(centralwidget);
        airLifeMenuBar = new QMenuBar(airLifeMainWindow__CustomerMainWindow);
        airLifeMenuBar->setObjectName(QString::fromUtf8("airLifeMenuBar"));
        airLifeMenuBar->setGeometry(QRect(0, 0, 403, 22));
        airLifeAccountMenu = new QMenu(airLifeMenuBar);
        airLifeAccountMenu->setObjectName(QString::fromUtf8("airLifeAccountMenu"));
        airLifeAccountAction = new QMenu(airLifeAccountMenu);
        airLifeAccountAction->setObjectName(QString::fromUtf8("airLifeAccountAction"));
        airLifeOrderMenu = new QMenu(airLifeMenuBar);
        airLifeOrderMenu->setObjectName(QString::fromUtf8("airLifeOrderMenu"));
        airLifeSearchMenu = new QMenu(airLifeMenuBar);
        airLifeSearchMenu->setObjectName(QString::fromUtf8("airLifeSearchMenu"));
        airLifeHelptMenu = new QMenu(airLifeMenuBar);
        airLifeHelptMenu->setObjectName(QString::fromUtf8("airLifeHelptMenu"));
        airLifeMainWindow__CustomerMainWindow->setMenuBar(airLifeMenuBar);
        statusbar = new QStatusBar(airLifeMainWindow__CustomerMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        airLifeMainWindow__CustomerMainWindow->setStatusBar(statusbar);

        airLifeMenuBar->addAction(airLifeOrderMenu->menuAction());
        airLifeMenuBar->addAction(airLifeSearchMenu->menuAction());
        airLifeMenuBar->addAction(airLifeAccountMenu->menuAction());
        airLifeMenuBar->addAction(airLifeHelptMenu->menuAction());
        airLifeAccountMenu->addAction(airLifeAccountAction->menuAction());
        airLifeAccountMenu->addSeparator();
        airLifeAccountMenu->addAction(airLifeAccountLogOutAction);
        airLifeAccountAction->addAction(airLifeAccountModifyPasswordAction);
        airLifeOrderMenu->addAction(airLifeCreateOrderAction);
        airLifeOrderMenu->addAction(airLifeDeleteOrderAction);
        airLifeSearchMenu->addAction(airLifeSearchFlightAction);
        airLifeHelptMenu->addAction(airLifeGetMoreHelpAction);

        retranslateUi(airLifeMainWindow__CustomerMainWindow);

        QMetaObject::connectSlotsByName(airLifeMainWindow__CustomerMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *airLifeMainWindow__CustomerMainWindow)
    {
        airLifeMainWindow__CustomerMainWindow->setWindowTitle(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\344\270\273\347\225\214\351\235\242", nullptr));
        airLifeAccountModifyPasswordAction->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
        airLifeAccountLogOutAction->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\347\231\273\345\207\272", nullptr));
        airLifeCreateOrderAction->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\345\210\233\345\273\272\350\256\242\345\215\225", nullptr));
        airLifeDeleteOrderAction->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\351\200\200\345\215\225", nullptr));
        airLifeSearchFlightAction->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\350\210\252\347\217\255\344\277\241\346\201\257", nullptr));
        airLifeGetMoreHelpAction->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "More", nullptr));
        actionw->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "w", nullptr));
        airLifeMUGroupBox->setTitle(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\345\212\237\350\203\275", nullptr));
        airLifeCreateOrderPushButton->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\345\210\233\345\273\272\350\256\242\345\215\225", nullptr));
        airLifeDeleteOrderPushButton->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\351\200\200\345\215\225", nullptr));
        airLifeSearchFlightPushButton->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\346\237\245\350\257\242", nullptr));
        airLifeUserUUIDLabel->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\347\224\250\346\210\267UUID\357\274\232", nullptr));
        airLifeSituationLabel->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\350\256\242\347\245\250\346\203\205\345\206\265\357\274\232", nullptr));
        airLifeUserNameLabel->setText(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\347\224\250\346\210\267\345\247\223\345\220\215\357\274\232", nullptr));
        airLifeAccountMenu->setTitle(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\350\264\246\346\210\267", nullptr));
        airLifeAccountAction->setTitle(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\345\257\206\347\240\201\347\256\241\347\220\206", nullptr));
        airLifeOrderMenu->setTitle(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\350\256\242\345\215\225", nullptr));
        airLifeSearchMenu->setTitle(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\346\237\245\350\257\242", nullptr));
        airLifeHelptMenu->setTitle(QCoreApplication::translate("airLifeMainWindow::CustomerMainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

} // namespace airLifeMainWindow

namespace airLifeMainWindow {
namespace Ui {
    class CustomerMainWindow: public Ui_CustomerMainWindow {};
} // namespace Ui
} // namespace airLifeMainWindow

#endif // UI_CUSTOMERMAINWINDOW_H

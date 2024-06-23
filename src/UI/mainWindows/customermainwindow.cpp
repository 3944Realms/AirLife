//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_CustomerMainWindow.h" resolved

#include "customermainwindow.h"
#include "ui_CustomerMainWindow.h"

namespace airLifeMainWindow {
    CustomerMainWindow::CustomerMainWindow(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::CustomerMainWindow) {
        ui->setupUi(this);
        currentAccount = nullptr;
        connect(ui->airLifeCreateOrderAction, &QAction::triggered,
                this, &CustomerMainWindow::airLifeCreateOrderActionSlot);
        connect(ui->airLifeDeleteOrderAction, &QAction::triggered,
                this, &CustomerMainWindow::airLifeDeleteOrderActionSlot);
        connect(ui->airLifeSearchFlightAction, &QAction::triggered,
                this, &CustomerMainWindow::airLifeSearchFlightActionSlot);
        connect(ui->airLifeAccountLogOutAction, &QAction::triggered,
                this, &CustomerMainWindow::airLifeAccountLogOutActionSlot);
        connect(ui->airLifeAccountModifyPasswordAction,&QAction::triggered,
                this, &CustomerMainWindow::airLifePasswordModifierSlot);
        orderCreatorWidget = new airLifeWidget::orderCreatorWidget();
        orderDestroyerWidget = new airLifeWidget::orderDestroyerWidget();
        informationFinderWidget = new airLifeWidget::informationFinderWidget();
        passwordModifierWidget = new airLifeWidget::PasswordModifier();
        connect(orderDestroyerWidget, &airLifeWidget::orderDestroyerWidget::destroyed,
                this ,&CustomerMainWindow::childWindowClosed);
        connect(orderCreatorWidget, &airLifeWidget::orderCreatorWidget::destroyed,
                this ,&CustomerMainWindow::childWindowClosed);
        connect(informationFinderWidget, &airLifeWidget::informationFinderWidget::destroyed,
                this ,&CustomerMainWindow::childWindowClosed);
        connect(passwordModifierWidget, &airLifeWidget::PasswordModifier::destroyed,
                this,&CustomerMainWindow::childWindowClosed);

    }

    void CustomerMainWindow::updateInfo() {
        currentAccount = dynamic_cast<airLifeDialog::loginDialog*>(airLifeHandler::GuiHandler::getLoginDialog())->getCurrentAccount();//测试
        if(currentAccount == nullptr) {
            setWindowTitle("主界面(测试用户账号，无UUID，为了安全，请用正式用户账号登录操作)");
            ui->airLifeUUIDLineEdit->setText("NULL");
            ui->airLifeUserNameLineEdit->setText("NULL");
            ui->airLifeSituationLineEdit->setText("测试账号无法订票");
        } else {
            ui->airLifeUUIDLineEdit->setText(currentAccount->getAccountUser()->getUUID().c_str());
            ui->airLifeUserNameLineEdit->setText(currentAccount->getAccountUser()->getName().c_str());
            ui->airLifeSituationLineEdit->setText(getAccountSituation(currentAccount));
        }
    }

    CustomerMainWindow::~CustomerMainWindow() {
        disconnectAllSignalsAndSlots();
        delete informationFinderWidget;
        delete orderDestroyerWidget;
        delete orderCreatorWidget;
        delete passwordModifierWidget;
        delete ui;
    }

    void CustomerMainWindow::airLifeAccountLogOutActionSlot() {
        this->close();
        airLifeHandler::GuiHandler::getInstance()->getLoginHandler()->resetLoginStatus();//重置登录状态
        airLifeHandler::GuiHandler::getInstance()->tryOpenLoginDialogShow();
    }

    void CustomerMainWindow::airLifeSearchFlightActionSlot() {
        this->hide();

        informationFinderWidget->setParent(this, Qt::Dialog);

        informationFinderWidget->show();
    }

    void CustomerMainWindow::airLifeCreateOrderActionSlot() {
        this->hide();

        orderCreatorWidget->setParent(this,Qt::Dialog);

        orderCreatorWidget->show();
    }

    void CustomerMainWindow::airLifeDeleteOrderActionSlot() {
        this->hide();

        orderDestroyerWidget->setParent(this,Qt::Dialog);

        orderDestroyerWidget->show();
    }

    void CustomerMainWindow::airLifePasswordModifierSlot() {
        this->hide();

        passwordModifierWidget->setParent(this,Qt::Dialog);

        passwordModifierWidget->show();
    }

    void CustomerMainWindow::on_airLifeCreateOrderPushButton_clicked() {
        airLifeCreateOrderActionSlot();
    }

    void CustomerMainWindow::on_airLifeDeleteOrderPushButton_clicked() {
        airLifeDeleteOrderActionSlot();
    }

    void CustomerMainWindow::on_airLifeSearchFlightPushButton_clicked() {
        airLifeSearchFlightActionSlot();
    }

    void CustomerMainWindow::childWindowClosed() {
        this->show();
    }

    void CustomerMainWindow::disconnectAllSignalsAndSlots() {
        //QAQ
        disconnect(orderDestroyerWidget, &airLifeWidget::orderDestroyerWidget::destroyed,
                this ,&CustomerMainWindow::childWindowClosed);
        disconnect(orderCreatorWidget, &airLifeWidget::orderCreatorWidget::destroyed,
                this ,&CustomerMainWindow::childWindowClosed);
        disconnect(informationFinderWidget, &airLifeWidget::informationFinderWidget::destroyed
                , this ,&CustomerMainWindow::childWindowClosed);
        disconnect(passwordModifierWidget, &airLifeWidget::PasswordModifier::destroyed,
                this,&CustomerMainWindow::childWindowClosed);
    }



} // airLifeMainWindow

//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_AdministerMainWindow.h" resolved

#include "administermainwindow.h"
#include "ui_AdministerMainWindow.h"

namespace airLifeMainWindow {
    AdministerMainWindow::AdministerMainWindow(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::AdministerMainWindow) {
        ui->setupUi(this);
        currentAccount = nullptr;
        connect(ui->airLifeAccountLogOutAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeAccountLogOutActionSlot);
        connect(ui->airLifeAddInformationAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeAddInformationActionSlot);
        connect(ui->airLifeMRInformationAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeMRInformationActionSlot);
        connect(ui->airLifeSearchFlightAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeSearchFlightActionSlot);
        connect(ui->airLifeAccountModifyPasswordAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifePasswordModifierSlot);
        connect(ui->airLifeSearchUserAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeUserAndAccountManagerActionSlot);
        informationFinderWidget = new airLifeWidget::informationFinderWidget();
        informationLoggerWidget = new airLifeWidget::informationLoggerWidget();
        informationModifierWidget = new airLifeWidget::informationModifierWidget();
        passwordModifierWidget = new airLifeWidget::PasswordModifier();
        userAndAccountManagerWidget = new airLifeWidget::UserAndAccountManager();
        connect(informationFinderWidget, &airLifeWidget::informationFinderWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        connect(informationLoggerWidget, &airLifeWidget::informationLoggerWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        connect(informationModifierWidget, &airLifeWidget::informationModifierWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        connect(passwordModifierWidget, &airLifeWidget::PasswordModifier::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        connect(userAndAccountManagerWidget, &airLifeWidget::UserAndAccountManager::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
    }

    void AdministerMainWindow::updateInfo() {
        currentAccount = dynamic_cast<airLifeDialog::loginDialog*>(airLifeHandler::GuiHandler::getLoginDialog())->getCurrentAccount();//测试
        if(currentAccount == nullptr) {
            setWindowTitle("主界面(测试管理员账号，无UUID，为了安全，请用正式管理账号登录操作)");
            ui->airLifeUserUUIDLineEdit->setText("NULL");
        } else {
            ui->airLifeUserUUIDLineEdit->setText(currentAccount->inf.AdministerUUID.c_str());
        }
    }

    AdministerMainWindow::~AdministerMainWindow() {
        disconnectAllSignalsAndSlots();
        delete informationFinderWidget;
        delete informationLoggerWidget;
        delete informationModifierWidget;
        delete passwordModifierWidget;
        delete userAndAccountManagerWidget;
        delete ui;
    }

    void AdministerMainWindow::airLifeAccountLogOutActionSlot() {
        this->close();//关闭当前界面
        airLifeHandler::GuiHandler::getInstance()->getLoginHandler()->resetLoginStatus();//重置登录状态
        airLifeHandler::GuiHandler::getInstance()->tryOpenLoginDialogShow();//打开登录框


    }

    void AdministerMainWindow::airLifeSearchFlightActionSlot() {
        this->hide();

        informationFinderWidget->setParent(this, Qt::Dialog);

        informationFinderWidget->show();
    }

    void AdministerMainWindow::airLifeAddInformationActionSlot() {
        this->hide();

        informationLoggerWidget->setParent(this, Qt::Dialog);

        informationLoggerWidget->show();
    }

    void AdministerMainWindow::airLifeMRInformationActionSlot() {
        this->hide();

        informationModifierWidget->setParent(this, Qt::Dialog);

        informationModifierWidget->show();
    }

    void AdministerMainWindow::airLifePasswordModifierSlot() {
        this->hide();

        passwordModifierWidget->setParent(this, Qt::Dialog);

        passwordModifierWidget->show();
    }

    void AdministerMainWindow::airLifeUserAndAccountManagerActionSlot() {
        this->hide();

        userAndAccountManagerWidget->setParent(this, Qt::Dialog);

        userAndAccountManagerWidget->show();
    }

    void AdministerMainWindow::disconnectAllSignalsAndSlots() {
        disconnect(informationFinderWidget, &airLifeWidget::informationFinderWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        disconnect(informationLoggerWidget, &airLifeWidget::informationLoggerWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        disconnect(informationModifierWidget, &airLifeWidget::informationModifierWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        disconnect(passwordModifierWidget, &airLifeWidget::PasswordModifier::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        disconnect(userAndAccountManagerWidget, &airLifeWidget::UserAndAccountManager::destroyed,
                   this, &AdministerMainWindow::childWindowClosed);
    }

    void AdministerMainWindow::on_airLifeAddInformationPushButton_clicked() {
        airLifeAddInformationActionSlot();
    }

    void AdministerMainWindow::on_airLifeMRInformationPushButton_clicked() {
        airLifeMRInformationActionSlot();
    }

    void AdministerMainWindow::childWindowClosed() {
        this->show();
    }



} // airLifeMainWindow

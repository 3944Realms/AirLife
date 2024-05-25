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

        connect(ui->airLifeAccountLogOutAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeAccountLogOutActionSlot);
        connect(ui->airLifeAddInformationAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeAddInformationActionSlot);
        connect(ui->airLifeMRInformationAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeMRInformationActionSlot);
        connect(ui->airLifeSearchFlightAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeSearchFlightActionSlot);
        informationFinderWidget = new airLifeWidget::informationFinderWidget();
        informationLoggerWidget = new airLifeWidget::informationLoggerWidget();
        informationModifierWidget = new airLifeWidget::informationModifierWidget();
        connect(informationFinderWidget, &airLifeWidget::informationFinderWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        connect(informationLoggerWidget, &airLifeWidget::informationLoggerWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        connect(informationModifierWidget, &airLifeWidget::informationModifierWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
    }

    AdministerMainWindow::~AdministerMainWindow() {
        disconnectAllSignalsAndSlots();
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

    void AdministerMainWindow::disconnectAllSignalsAndSlots() {
        disconnect(informationFinderWidget, &airLifeWidget::informationFinderWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        disconnect(informationLoggerWidget, &airLifeWidget::informationLoggerWidget::destroyed,
                this, &AdministerMainWindow::childWindowClosed);
        disconnect(informationModifierWidget, &airLifeWidget::informationModifierWidget::destroyed,
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

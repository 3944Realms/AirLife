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
        informationFinderWidget = new airLifeWidget::informationFinderWidget();
        informationLoggerWidget = new airLifeWidget::informationLoggerWidget();
        informationModifierWidget = new airLifeWidget::informationModifierWidget();
        connect(informationFinderWidget, &airLifeWidget::informationFinderWidget::destroyed,
                this, &AdministerMainWindow::airLifeSearchFlightActionSlot);
        connect(informationLoggerWidget, &airLifeWidget::informationLoggerWidget::destroyed,
                this, &AdministerMainWindow::airLifeAddInformationActionSlot);
        connect(informationModifierWidget, &airLifeWidget::informationModifierWidget::destroyed,
                this, &AdministerMainWindow::airLifeMRInformationActionSlot);
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
                this, &AdministerMainWindow::airLifeSearchFlightActionSlot);
        disconnect(informationLoggerWidget, &airLifeWidget::informationLoggerWidget::destroyed,
                this, &AdministerMainWindow::airLifeAddInformationActionSlot);
        disconnect(informationModifierWidget, &airLifeWidget::informationModifierWidget::destroyed,
                this, &AdministerMainWindow::airLifeMRInformationActionSlot);
    }

    void AdministerMainWindow::on_airLifeAddInformationPushButton_clicked() {

    }

    void AdministerMainWindow::on_airLifeMRInformationPushButton_clicked() {

    }

    void AdministerMainWindow::childWindowClosed() {

    }


} // airLifeMainWindow

//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_CustomerMainWindow.h" resolved

#include "customermainwindow.h"
#include "ui_CustomerMainWindow.h"

namespace airLifeMainWindow {
    CustomerMainWindow::CustomerMainWindow(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::CustomerMainWindow) {
        ui->setupUi(this);

        connect(ui->airLifeCreateOrderAction, &QAction::triggered,
                this, &CustomerMainWindow::airLifeCreateOrderActionSlot);
        connect(ui->airLifeDeleteOrderAction, &QAction::triggered,
                this, &CustomerMainWindow::airLifeDeleteOrderActionSlot);
        connect(ui->airLifeSearchFlightAction, &QAction::triggered,
                this, &CustomerMainWindow::airLifeSearchFlightActionSlot);
        connect(ui->airLifeAccountLogOutAction, &QAction::triggered,
                this, &CustomerMainWindow::airLifeAccountLogOutActionSlot);
        orderCreatorWidget = new airLifeWidget::orderCreatorWidget();
        orderDestroyerWidget = new airLifeWidget::orderDestroyerWidget();
        informationFinderWidget = new airLifeWidget::informationFinderWidget();
        connect(orderDestroyerWidget, &airLifeWidget::orderDestroyerWidget::destroyed,
                this ,&CustomerMainWindow::childWindowClosed);
        connect(orderCreatorWidget, &airLifeWidget::orderCreatorWidget::destroyed,
                this ,&CustomerMainWindow::childWindowClosed);
        connect(informationFinderWidget, &airLifeWidget::informationFinderWidget::destroyed
                , this ,&CustomerMainWindow::childWindowClosed);

    }

    CustomerMainWindow::~CustomerMainWindow() {
        disconnectAllSignalsAndSlots();
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
    }

} // airLifeMainWindow

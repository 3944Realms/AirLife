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
        connect(ui->airLifeAccountLogOutAction, &QAction::triggered,
                this,&CustomerMainWindow::airLifeAccountLogOutActionSlot);
    }

    CustomerMainWindow::~CustomerMainWindow() {
        delete ui;
    }

    void CustomerMainWindow::airLifeAccountLogOutActionSlot() {
        this->close();
        airLifeHandler::GuiHandler::getInstance()->getLoginHandler()->resetLoginStatus();//重置登录状态
        airLifeHandler::GuiHandler::getInstance()->tryOpenLoginDialogShow();
    }
} // airLifeMainWindow

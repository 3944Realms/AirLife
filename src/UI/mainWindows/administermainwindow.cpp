//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AdministerMainWindow.h" resolved

#include "administermainwindow.h"
#include "ui_AdministerMainWindow.h"

namespace airLifeMainWindow {
    AdministerMainWindow::AdministerMainWindow(QWidget *parent) :
            QMainWindow(parent), ui(new Ui::AdministerMainWindow) {
        ui->setupUi(this);
        connect(ui->airLifeAccountLogOutAction, &QAction::triggered, this,
                &AdministerMainWindow::airLifeAccountLogOutActionSlot);
    }

    AdministerMainWindow::~AdministerMainWindow() {
        delete ui;
    }

    void AdministerMainWindow::airLifeAccountLogOutActionSlot() {
        this->close();//关闭当前界面
        airLifeHandler::GuiHandler::getInstance()->getLoginHandler()->resetLoginStatus();//重置登录状态
        airLifeHandler::GuiHandler::getInstance()->tryOpenLoginDialogShow();//打开登录框


    }
} // airLifeMainWindow

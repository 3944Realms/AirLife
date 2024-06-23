//
// Created by f2561 on 24-6-9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserAndAccountManager.h" resolved

#include "userandaccountmanager.h"
#include "ui_UserAndAccountManager.h"

namespace airLifeWidget {
    UserAndAccountManager::UserAndAccountManager(QWidget *parent) :
            QWidget(parent), ui(new Ui::UserAndAccountManager) {
        ui->setupUi(this);
    }

    UserAndAccountManager::~UserAndAccountManager() {
        delete ui;
    }

    void UserAndAccountManager::on_airLifeBackPushButton_clicked() {
        this->close();
        emit destroyed();
    }
} // airLifeWidget

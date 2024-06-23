//
// Created by f2561 on 24-6-23.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PasswordModifier.h" resolved

#include "passwordmodifier.h"
#include "ui_PasswordModifier.h"

namespace airLifeWidget {
    PasswordModifier::PasswordModifier(QWidget *parent) :
            QWidget(parent), ui(new Ui::PasswordModifier) {
        ui->setupUi(this);
    }

    PasswordModifier::~PasswordModifier() {
        delete ui;
    }

    void PasswordModifier::on_airLifeBackPushButton_clicked() {
        this->close();
        emit destroyed();
    }
} // airLifeWidget

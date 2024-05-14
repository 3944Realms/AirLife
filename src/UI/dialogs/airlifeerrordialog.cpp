//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AirLifeErrorDialog.h" resolved

#include "airlifeerrordialog.h"
#include "ui_AirLifeErrorDialog.h"

namespace airLifeDialog {
    AirLifeErrorDialog::AirLifeErrorDialog(QWidget *parent) :
            QDialog(parent), ui(new Ui::AirLifeErrorDialog) {
        ui->setupUi(this);
    }

    AirLifeErrorDialog::~AirLifeErrorDialog() {
        delete ui;
    }
} // airLifeDialog

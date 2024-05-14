//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AirLifeRunnigDialog.h" resolved

#include "airliferunnigdialog.h"
#include "ui_AirLifeRunnigDialog.h"

namespace airLifeDialog {
    AirLifeRunnigDialog::AirLifeRunnigDialog(QWidget *parent) :
            QDialog(parent), ui(new Ui::AirLifeRunnigDialog) {
        ui->setupUi(this);
    }

    AirLifeRunnigDialog::~AirLifeRunnigDialog() {
        delete ui;
    }
} // airLifeDialog

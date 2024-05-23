//
// Created by f2561 on 24-5-15.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_AirLifeRunningDialog.h" resolved

#include "airliferunningdialog.h"
#include "ui_AirLifeRunningDialog.h"

namespace airLifeDialog {
    AirLifeRunningDialog::AirLifeRunningDialog(QWidget *parent) :
            QDialog(parent), ui(new Ui::AirLifeRunningDialog) {
        ui->setupUi(this);
    }

    AirLifeRunningDialog::~AirLifeRunningDialog() {
        delete ui;
    }
} // airLifeDialog

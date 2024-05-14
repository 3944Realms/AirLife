//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (run Qt uic code generator) to get "ui_AirLifeInfoDialog.h" resolved

#include "airlifeinfodialog.h"
#include "ui_AirLifeInfoDialog.h"

namespace airLifeDialog {
    AirLifeInfoDialog::AirLifeInfoDialog(QWidget *parent) :
            QDialog(parent), ui(new Ui::AirLifeInfoDialog) {
        ui->setupUi(this);
    }

    void AirLifeInfoDialog::on_airLifeBackPushButton_clicked() {
        this->close();
    }

    AirLifeInfoDialog::~AirLifeInfoDialog() {
        delete ui;
    }
} // airLifeDialog

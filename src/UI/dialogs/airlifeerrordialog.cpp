//
// Created by f2561 on 24-5-13.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_AirLifeErrorDialog.h" resolved

#include "airlifeerrordialog.h"

#include <utility>
#include "ui_AirLifeErrorDialog.h"

namespace airLifeDialog {
    AirLifeErrorDialog::AirLifeErrorDialog(QWidget *parent, const QString& errorMessage) :
            QDialog(parent), ui(new Ui::AirLifeErrorDialog) {
        ui->setupUi(this);
        error_Message = errorMessage;
        ui->airLifeErrorLogOutput->setText(error_Message);
    }

    AirLifeErrorDialog::~AirLifeErrorDialog() {
        delete ui;
    }


    void AirLifeErrorDialog::on_airLifeSurePushButton_clicked() {
        this->close();
        emit destroyed();
    }

    void AirLifeErrorDialog::closeEvent(QCloseEvent *) {
        emit destroyed();
        this->close();
    }

    void AirLifeErrorDialog::setMessage(const QString& mess) {
        ui->airLifeErrorLogOutput->setText(mess);
    }

} // airLifeDialog

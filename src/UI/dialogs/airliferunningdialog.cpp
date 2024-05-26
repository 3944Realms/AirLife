//
// Created by f2561 on 24-5-15.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_AirLifeRunningDialog.h" resolved

#include <QMessageBox>
#include "airliferunningdialog.h"
#include "ui_AirLifeRunningDialog.h"

namespace airLifeDialog {
    AirLifeRunningDialog::AirLifeRunningDialog(QWidget *parent) :
            QDialog(parent), ui(new Ui::AirLifeRunningDialog) {
        ui->setupUi(this);
        processValue = 0;
        setProcessBarCurrentValue(processValue);
        connect(ui->airLifeProgressBar, &QProgressBar::valueChanged, this, &AirLifeRunningDialog::onAirLifeProgressBarValueChange);
    }

    AirLifeRunningDialog::~AirLifeRunningDialog() {
        delete ui;
    }

    void AirLifeRunningDialog::setProcessBarCurrentValue(int processValue_) {
        processValue = processValue_;
        ui->airLifeProgressBar->setValue(processValue_);
    }
    void AirLifeRunningDialog::processBarValueChanged(int valueChanged) {
        processValue += valueChanged;
        ui->airLifeProgressBar->setValue(processValue);
    }
    int AirLifeRunningDialog::getProcessBarValue() {
        return ui->airLifeProgressBar->value();
    }

    void AirLifeRunningDialog::resetMessage() {
        message = "";
        ui->airLifeLogOutput->clear();
    }

    void AirLifeRunningDialog::addMessage(const QString& pMessage) {
        message += ("\n"+pMessage);
        ui->airLifeLogOutput->setText("");
    }

    void AirLifeRunningDialog::setMessage(const QString &pMessage) {
        message = pMessage;
        ui->airLifeLogOutput->setText(pMessage);
    }
    void AirLifeRunningDialog::onAirLifeProgressBarValueChange() {
        processValue = getProcessBarValue();
        if(processValue == 100) {
            this->close();
            emit destroyed();
        }
    }

    void AirLifeRunningDialog::closeEvent(QCloseEvent *event) {
        if(processValue == 100) {
            this->close();
            emit destroyed();
        } else {

        }
    }


} // airLifeDialog

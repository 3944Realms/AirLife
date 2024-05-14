//
// Created by f2561 on 24-5-12.
//

// You may need to build the project (run Qt uic code generator) to get "ui_loginDialog.h" resolved

#include "logindialog.h"
#include "ui_loginDialog.h"
#include "../easterEgg/hui.h"

namespace airLifeDialog {
    loginDialog::loginDialog(QWidget *parent) :
            QDialog(parent), ui(new Ui::loginDialog) {
        ui->setupUi(this);
    }

    void loginDialog::on_loginButton_clicked() {
        if(ui->acc_inp->text() == "Mommy" && ui->pas_inp->text() == "1314520"){
            auto * hui = new egg::hui();
            hui->show();
        }
    }

    loginDialog::~loginDialog() {
        delete ui;
    }
} // airLifeDialog

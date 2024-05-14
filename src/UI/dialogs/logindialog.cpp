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
        }else{
            //if 用户数据文件里找到用户
                //if 用户数据文件里密码的hash值与用户输入的明文转成hash一致
                    //根据用户类型去寻找对于的界面
                //else
        }
    }
    void loginDialog::on_cancelButton_clicked() {
        this->close();
    }

    loginDialog::~loginDialog() {
        delete ui;
    }
} // airLifeDialog

//
// Created by f2561 on 24-5-12.
//

// You may need to build the project (initTaskRun Qt uic code generator) to get "ui_loginDialog.h" resolved


#include "logindialog.h"
#include "ui_loginDialog.h"

/**
 * 未知的问题： 第一次加载时在不正确的位置
 * @date 2024/05/30
 */
namespace airLifeDialog {
    loginDialog::loginDialog(QWidget *parent) :
            QDialog(parent), ui(new Ui::loginDialog) {
        ui->setupUi(this);
        tipWidget = new airLifeTipWidget::InputTipWidget(this, Qt::red, Qt::white, true, 2000);
    }

    void loginDialog::on_loginButton_clicked() {
        airLifeHandler::GuiHandler* pGuiHandler = airLifeHandler::GuiHandler::getInstance();
        airLifeHandler::LoginHandler* pLoginHandler = pGuiHandler->getLoginHandler();
        if(ui->acc_inp->text() == "Mommy" && ui->pas_inp->text() == "1314520"){
            auto * hui = new egg::hui();
            ui->acc_inp->setText("");
            ui->pas_inp->setText("");
            hui->show();
        }else{
            //Test#2用户
            if(ui->acc_inp->text() == "User" && ui->pas_inp->text() == "") {
                pLoginHandler->setLoginStatus(airLifeHandler::AccountStatus::USER_LOGIN_IN);
                int result = pGuiHandler->tryOpenMainWindowsShow();
                ui->acc_inp->setText("");
                ui->pas_inp->setText("");
                if(result == -1) std::cerr<<"Please invoke GUI method first to init Widget!"<<std::endl;
                else if(result == -2) std::cerr<<""<<std::endl;
            }
            //Test#1管理员
            else if(ui->acc_inp->text() == "Admin" && ui->pas_inp->text() == "") {
                pLoginHandler->setLoginStatus(airLifeHandler::AccountStatus::ADMIN_LOGIN_IN);
                int result = pGuiHandler->tryOpenMainWindowsShow();
                ui->acc_inp->setText("");
                ui->pas_inp->setText("");
                if(result == -1) std::cerr<<"Please invoke GUI method first to init Widget!"<<std::endl;
                else if(result == -2) std::cerr<<""<<std::endl;
            }
            else {
                tipWidget->setText("The user does not exist or the password is incorrect.");
                tipWidget->move(ui->acc_lab->mapToGlobal(QPoint(0,-tipWidget->height())));
                tipWidget->show();
            }
            //if 用户数据文件里找到用户
                //if 用户数据文件里密码的hash值与用户输入的明文转成hash的结果校验一致
                    //根据用户类型去寻找对于实例
                //else
                    //提示 用户名或密码错误
            //else 该账号不存在
        }
    }
    void loginDialog::on_cancelButton_clicked() {
        this->close();
    }

    loginDialog::~loginDialog() {
        delete tipWidget;
        delete ui;
    }
} // airLifeDialog

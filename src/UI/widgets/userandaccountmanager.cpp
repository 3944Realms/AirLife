//
// Created by f2561 on 24-6-9.
//

// You may need to build the project (run Qt uic code generator) to get "ui_UserAndAccountManager.h" resolved
#include "../../Base/component.h"
#include "userandaccountmanager.h"
#include "ui_UserAndAccountManager.h"

namespace airLifeWidget {
    UserAndAccountManager::UserAndAccountManager(QWidget *parent) :
            QWidget(parent), ui(new Ui::UserAndAccountManager) {
        ui->setupUi(this);
        tipWidget = new airLifeTipWidget::AirLifeInputTipWidget(nullptr,Qt::red);
        connect(ui->airLifeAccountTypeComboBox_Re, &QComboBox::currentTextChanged,
                [=](const QString &text) {
            if(text == "(请选择)") {
                ui->airLifeUUIDLineEdit_Re->clear();
                ui->airLifeUserNameLineEdit_Re->clear();
                ui->airLifeUUIDLineEdit_Re->setEnabled(false);
                ui->airLifeUserNameLineEdit_Re->setEnabled(false);
                disconnect(ui->airLifeAccountUUIDComboBox_Re, &QComboBox::currentTextChanged, nullptr, nullptr);
            }
            else if(text == "普通用户") {
                ui->airLifeUUIDLineEdit_Re->clear();
                ui->airLifeUUIDLineEdit_Re->setEnabled(true);
                ui->airLifeUserNameLineEdit_Re->clear();
                ui->airLifeUserNameLineEdit_Re->setEnabled(true);
                ui->airLifeUUIDLineEdit_Re->setText(ui->airLifeAccountUUIDComboBox_Re->currentText());
                connect(ui->airLifeAccountUUIDComboBox_Re, &QComboBox::currentTextChanged,
                        [=](const QString &text){
                    ui->airLifeUUIDLineEdit_Re->setText(text);
                });
            }
            else if(text == "管理员") {
                ui->airLifeUUIDLineEdit_Re->clear();
                ui->airLifeUUIDLineEdit_Re->setEnabled(false);
                ui->airLifeUserNameLineEdit_Re->clear();
                ui->airLifeUserNameLineEdit_Re->setEnabled(false);
                disconnect(ui->airLifeAccountUUIDComboBox_Re, &QComboBox::currentTextChanged, nullptr, nullptr);
            }
        });
    }

    UserAndAccountManager::~UserAndAccountManager() {
        delete tipWidget;
        delete ui;
    }

    void UserAndAccountManager::on_airLifeBackPushButton_clicked() {
        this->close();
        emit destroyed();
    }

    void UserAndAccountManager::on_airLifeSearchButton_clicked() {
       auto AccountUUID = ui->airLifeAccountUUIDComboBox->currentText();
       airLifeHandler::AccountType AccountType = airLifeHandler::UNKNOWN;
       bool isFound = false;
       COMPONENT::Account *targetAccount = nullptr;
       for(auto i : COMPONENT::AccountList) {
           if(i->getAccountType() == airLifeHandler::DEFAULT) {
               if(i->getAccountUser()->getUUID() == AccountUUID.toStdString()) {
                   targetAccount = i;
                   AccountType = airLifeHandler::DEFAULT;
                   isFound = true;
                   break;
               }
           } else if(i->getAccountType() == airLifeHandler::ADMIN) {
               if(i->inf.getAdminUUID() == AccountUUID.toStdString()) {
                   targetAccount = i;
                   AccountType = airLifeHandler::ADMIN;
                   isFound = true;
                   break;
               }
           }
       }
       if(isFound) {
           if(AccountType == airLifeHandler::DEFAULT) {
                ui->airLifeAccountTypeLineEdit->setText("普通用户");
                ui->airLifeUUIDLineEdit->setText(targetAccount->getAccountUser()->getUUID().c_str());
                ui->airLifeUserNameLineEdit->setText(targetAccount->inf.returnAccUser()->getName().c_str());
           } else if (AccountType == airLifeHandler::ADMIN) {
               ui->airLifeAccountTypeLineEdit->setText("管理员");
           } else {
               tipWidget->setText("This is an internal fault while load this data file which should happen.");
               tipWidget->move(ui->airLifeAccountUUIDComboBox->mapToGlobal(QPoint(0,-tipWidget->height())));
               tipWidget->show();
           }
       } else {
           tipWidget->setText("Not Found");
           tipWidget->move(ui->airLifeAccountUUIDComboBox->mapToGlobal(QPoint(0,-tipWidget->height())));
           tipWidget->show();
       }
    }

    void UserAndAccountManager::on_airLifeFlushButton_clicked() {
        auto size = (unsigned int) COMPONENT::AccountList.size();
        auto Qsize = QString(std::to_string(size).c_str());
        ui->airLifeUserNumberLineEdit->setText(Qsize);
    }

    void UserAndAccountManager::on_airLifeSearchButton_2_clicked() {
        auto AccountUUID = ui->airLifeAccountUUIDComboBox_Ma->currentText();
        airLifeHandler::AccountType AccountType = airLifeHandler::UNKNOWN;
        bool isFound = false;
        COMPONENT::Account *targetAccount = nullptr;
        for(auto i : COMPONENT::AccountList) {
            if(i->getAccountType() == airLifeHandler::DEFAULT) {
                if(i->inf.returnAccUser()->getUUID() == AccountUUID.toStdString()) {
                    targetAccount = i;
                    AccountType = airLifeHandler::DEFAULT;
                    isFound = true;
                    break;
                }
            } else if(i->getAccountType() == airLifeHandler::ADMIN) {
                if(i->inf.getAdminUUID() == AccountUUID.toStdString()) {
                    targetAccount = i;
                    AccountType = airLifeHandler::ADMIN;
                    isFound = true;
                    break;
                }
            }
        }
        if(isFound) {
            if(AccountType == airLifeHandler::DEFAULT) {
                ui->airLifeAccountTypeComboBox_Ma->setCurrentText("普通用户");
                ui->airLifeUUIDLineEdit_Ma->setText(targetAccount->getAccountUser()->getUUID().c_str());
                ui->airLifeUserNameLineEdit_Ma->setText(targetAccount->inf.returnAccUser()->getName().c_str());
            } else if (AccountType == airLifeHandler::ADMIN) {
                ui->airLifeAccountTypeComboBox_Ma->setCurrentText("管理员");
            } else {
                tipWidget->setText("This is an internal fault while load this data file which should happen.");
                tipWidget->move(ui->airLifeAccountUUIDComboBox->mapToGlobal(QPoint(0,-tipWidget->height())));
                tipWidget->show();
            }
        } else {
            tipWidget->setText("Not Found");
            tipWidget->move(ui->airLifeAccountUUIDComboBox_Ma->mapToGlobal(QPoint(0,-tipWidget->height())));
            tipWidget->show();
        }
    }

    void UserAndAccountManager::on_airLifeRegisterPushButton_clicked() {
        airLifeHandler::AccountType targetAccountType;
        std::string userName;
        if((ui->airLifeAccountTypeComboBox_Re->currentText()) != "(请选择)"){
            if(ui->airLifeAccountTypeComboBox_Re->currentText() == "普通用户") {
                userName = ui->airLifeUserNameLineEdit_Re->text().toStdString();
            } else if((ui->airLifeAccountTypeComboBox_Re->currentText()) == "管理员") {

            }
        } else {

            return;
        }
        std::string AccountUUID(ui->airLifeAccountUUIDComboBox_Re->currentText().toStdString());
        std::hash<std::string> strHash;
        std::string PasswordHash =  std::to_string(strHash(ui->pas_inp->text().toStdString()));

    }
} // airLifeWidget

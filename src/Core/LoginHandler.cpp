//
// Created by f2561 on 24-5-12.
//

#include "LoginHandler.h"
namespace airLifeHandler {
    LoginHandler::LoginHandler() {
        LoginHandler::hasLogged = false;
        LoginHandler::accStatus = airLifeHandler::NOT_LOGGER_IN;
        LoginHandler::accType = airLifeHandler::UNKNOWN;
        LoginHandler::isEgg = false;
    }
    bool LoginHandler::hasAccountLogged() const {
            return hasLogged;
    }
    void LoginHandler::setLoginStatus(airLifeHandler::AccountStatus status) {
        switch (status) {
            case NOT_LOGGER_IN:
                hasLogged = false;
                break;
            case USER_LOGIN_IN:
                hasLogged = true;
                accType = DEFAULT;
                break;
            case ADMIN_LOGIN_IN:
                hasLogged = true;
                accType =ADMIN;
                break;
            case FAULT_SYSTEM_STATUS:
                hasLogged = false;
                accType = UNKNOWN;
                /*非法状态处理逻辑（待完善）*/
                /*非法状态处理逻辑（待完善）*/
                /*非法状态处理逻辑（待完善）*/
                break;
        }
    }

    void LoginHandler::enable() {
        isEgg = true;
    }

    LoginHandler::~LoginHandler(){
//        delete this;
    }

    AccountType LoginHandler::getAccountType() {
        return accType;
    }
}
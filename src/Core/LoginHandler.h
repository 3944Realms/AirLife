//
// Created by f2561 on 24-5-12.
//

#ifndef AIRLIFE_LOGINHANDLER_H
#define AIRLIFE_LOGINHANDLER_H
namespace airLifeHandler {
    enum AccountStatus {
        NOT_LOGGER_IN,
        USER_LOGIN_IN,
        ADMIN_LOGIN_IN,
        FAULT_SYSTEM_STATUS
    };
    enum AccountType {
        DEFAULT,
        ADMIN,
        UNKNOWN
    };
    class LoginHandler {
    private:
        bool hasLogged;
        AccountStatus accStatus;
        AccountType accType;

    public:
        LoginHandler();
        bool hasAccountLogged() const;
        void setLoginStatus(AccountStatus status);
        AccountType getAccountType();
        void enable();
        ~LoginHandler();
        bool isEgg;
    };
}


#endif //AIRLIFE_LOGINHANDLER_H

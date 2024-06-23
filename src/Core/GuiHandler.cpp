//
// Created by f2561 on 24-5-13.
//

#include "GuiHandler.h"

namespace airLifeHandler {
    GuiHandler* GuiHandler::instance = nullptr;
    std::once_flag GuiHandler::onceFlag;
    QMainWindow *GuiHandler::user = nullptr, *GuiHandler::admin = nullptr;
    QDialog *GuiHandler::login = nullptr;

    GuiHandler::GuiHandler(const airLifeHandler::LoginHandler &handler) : loginHandler(handler) {}

    airLifeHandler::GuiHandler* GuiHandler::getInstance() {

        std::call_once(onceFlag, [](){
            instance = new GuiHandler(LoginHandler());
        });
        return instance;
    }


    void GuiHandler::ShowDialog(QDialog *dialog) {
        dialog->show();
    }

    void GuiHandler::ShowWidget(QWidget *widget) {
        widget->show();
    }

    void GuiHandler::ShowMainWindows(QMainWindow *mainWindow) {
        mainWindow->show();
    }

    void GuiHandler::Gui(QDialog &loginDialog, QMainWindow &administerWindow, QMainWindow &userWindow) {
        admin = &administerWindow;
        user = &userWindow;
        login = &loginDialog;
        if (loginHandler.hasAccountLogged()) {
            loginDialog.hide();
            switch (loginHandler.getAccountType()) {
                case DEFAULT:
                    userWindow.show();
                    break;
                case ADMIN:
                    administerWindow.show();
                    break;
                case UNKNOWN:
                    break;
            }
        }
        else{
            loginDialog.show();
        }
    }

    LoginHandler *GuiHandler::getLoginHandler() {
        return &loginHandler;
    }

//    void GuiHandler::switchMainWindow() {
//
//    }

    void GuiHandler::setLoginHandler(const LoginHandler &handler) {
        loginHandler = handler;
    }

#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
    int GuiHandler::tryOpenLoginDialogShow() {
        if(login == nullptr) return -1;
        login->show();
        return 0;
    }
#pragma clang diagnostic pop

    int GuiHandler::tryOpenMainWindowsShow() {
        if(user == nullptr || admin == nullptr) return -1;
        if (loginHandler.hasAccountLogged()) {
            login->hide();
            switch (loginHandler.getAccountType()) {
                case DEFAULT:
                    login->hide();
                    user->show();
                    return 0;
                case ADMIN:
                    login->hide();
                    admin->show();
                    return 0;
                case UNKNOWN:
                    return -2;
            }
        }
        return 0;
    }
}// airLifeHandler
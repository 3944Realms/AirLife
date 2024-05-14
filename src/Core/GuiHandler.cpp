//
// Created by f2561 on 24-5-13.
//

#include "GuiHandler.h"

namespace airLifeHandler {
    GuiHandler* GuiHandler::instance = nullptr;
    std::once_flag GuiHandler::onceFlag;

    GuiHandler::GuiHandler(const airLifeHandler::LoginHandler &handler) : loginHandler(handler) {}

    airLifeHandler::GuiHandler* GuiHandler::getInstance(const airLifeHandler::LoginHandler &handler) {
        static LoginHandler hd = handler;
        std::call_once(onceFlag, [](){
            instance = new GuiHandler(hd);
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
        loginDialog.show();
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
    }
}// airLifeHandler
//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_GUIHANDLER_H
#define AIRLIFE_GUIHANDLER_H
#include <QtWidgets>
#include <mutex>
#include "LoginHandler.h"
#include "../UI/test/testwindows.h"

namespace airLifeHandler {

    class GuiHandler {//单例模式
    private:
        static GuiHandler* instance;
        static std::once_flag onceFlag;
        static QMainWindow *admin,*user;
        static QDialog *login;
         LoginHandler loginHandler;
        explicit GuiHandler(const LoginHandler& handler);

    public:
        GuiHandler(const GuiHandler&) = delete;
        GuiHandler& operator=(const GuiHandler&) = delete;
        static airLifeHandler::GuiHandler * getInstance();
        void setLoginHandler(const LoginHandler& handler);
        int tryOpenLoginDialogShow();
        int tryOpenMainWindowsShow();
        static void ShowWidget(QWidget *widget);
        static void ShowDialog(QDialog *dialog);
        static void ShowMainWindows(QMainWindow * mainWindow);
        static void switchMainWindow();
        void Gui(QDialog &loginDialog, QMainWindow &administerWindow, QMainWindow &userWindow);
        LoginHandler* getLoginHandler();

    };

} // airLifeHandler

#endif //AIRLIFE_GUIHANDLER_H

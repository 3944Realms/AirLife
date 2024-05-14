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

    class GuiHandler {
    private:
        static GuiHandler* instance;
        static std::once_flag onceFlag;
        LoginHandler loginHandler;
        explicit GuiHandler(const LoginHandler& handler);

    public:
        GuiHandler(const GuiHandler&) = delete;
        GuiHandler& operator=(const GuiHandler&) = delete;
        static airLifeHandler::GuiHandler * getInstance(const LoginHandler& handler);
        static void ShowWidget(QWidget *widget);
        static void ShowDialog(QDialog *dialog);
        static void ShowMainWindows(QMainWindow * mainWindow);
        void Gui(QDialog &loginDialog, QMainWindow &administerWindow, QMainWindow &userWindow);

    };

} // airLifeHandler

#endif //AIRLIFE_GUIHANDLER_H

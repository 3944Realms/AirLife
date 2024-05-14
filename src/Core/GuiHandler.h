//
// Created by f2561 on 24-5-13.
//

#ifndef AIRLIFE_GUIHANDLER_H
#define AIRLIFE_GUIHANDLER_H
#include <QtWidgets>
#include "LoginHandler.h"
#include "../UI/test/testwindows.h"

namespace airLifeHandler {

    class GuiHandler {
    private:
         LoginHandler loginHandler;
    public:
        static void ShowWidget(QWidget *widget);
        static void ShowDialog(QDialog *dialog);
        static void ShowMainWindows(QMainWindow * mainWindow);
        void Gui(QDialog &loginDialog, QMainWindow &administerWindow, QMainWindow &userWindow);
        explicit GuiHandler(const LoginHandler& handler);
    };

} // airLifeHandler

#endif //AIRLIFE_GUIHANDLER_H

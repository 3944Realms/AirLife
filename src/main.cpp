#include <iostream>
#include <QtWidgets>
#include "Core/GuiHandler.h"
#include "Core/LoginHandler.h"
#include "UI/dialogs/logindialog.h"
#include "UI/mainWindows/administermainwindow.h"
#include "UI/mainWindows/customermainwindow.h"

int main(int argc,char *argv[]) {
    std::cout<<__cplusplus;
    QApplication a(argc,argv);
    QApplication::setWindowIcon(QIcon(":/Logo/airLifeLogo.ico"));
    airLifeHandler::LoginHandler loginHandler;
    airLifeHandler::GuiHandler* guiHandler = airLifeHandler::GuiHandler::getInstance();
    guiHandler->setLoginHandler(loginHandler);
    airLifeDialog::loginDialog loginDialog;
    airLifeMainWindow::CustomerMainWindow CuWi;
    airLifeMainWindow::AdministerMainWindow AdWi;
    guiHandler->Gui(loginDialog,AdWi,CuWi);
    int result = QApplication::exec();
    return result;
}

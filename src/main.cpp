/*开关位于根CMake下target_compile_definitions处*/


#include <iostream>
#include <QtWidgets>
#include <vector>
#include "Core/GuiHandler.h"
#include "Core/LoginHandler.h"
#include "Core/InitialHandler.h"
#include "Core/UpdateHandler.h"
#include "UI/dialogs/logindialog.h"
#include "UI/mainWindows/administermainwindow.h"
#include "UI/mainWindows/customermainwindow.h"
#include "UI/test/testwindows.h"

void init(std::vector<COMPONENT::Area *> &areaList,
          std::vector<COMPONENT::Airplane *> &airplaneList,
          std::vector<COMPONENT::Flight *> &flightList,
          std::vector<COMPONENT::Orders *> &orderList,
          std::vector<COMPONENT::Chargebacks *> &chargebackList,
          std::vector<COMPONENT::User *> &userList,
          std::vector<COMPONENT::Account *> &accountList);

void save(std::vector<COMPONENT::Area *> &areaList,
          std::vector<COMPONENT::Airplane *> &airplaneList,
          std::vector<COMPONENT::Flight *> &flightList,
          std::vector<COMPONENT::Orders *> &orderList,
          std::vector<COMPONENT::Chargebacks *> &chargebackList,
          std::vector<COMPONENT::User *> &userList,
          std::vector<COMPONENT::Account *> &accountList);

int main(int argc,char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setWindowIcon(QIcon(":/Logo/airLifeLogo.ico"));
    airLifeHandler::LoginHandler loginHandler;
    airLifeHandler::GuiHandler *guiHandler = airLifeHandler::GuiHandler::getInstance();
    guiHandler->setLoginHandler(loginHandler);
    if(!AIR_LIFE_DEBUG_MODE && !AIR_LIFE_TEST_MODE){
        /*NormalMode*/
        std::vector<COMPONENT::Area *> AreaList;
        std::vector<COMPONENT::Airplane *> AirplaneList;
        std::vector<COMPONENT::Flight *> FlightList;
        std::vector<COMPONENT::Orders *> OrderList;
        std::vector<COMPONENT::Chargebacks *> ChargebackList;
        std::vector<COMPONENT::User *> UserList;
        std::vector<COMPONENT::Account *> AccountList;
        init(AreaList, AirplaneList, FlightList, OrderList, ChargebackList, UserList, AccountList);
        std::cout << __cplusplus << std::endl;
        airLifeDialog::loginDialog loginDialog;
        airLifeMainWindow::CustomerMainWindow CuWi;
        airLifeMainWindow::AdministerMainWindow AdWi;
        guiHandler->Gui(loginDialog, AdWi, CuWi);
        int result = QApplication::exec();
        save(AreaList, AirplaneList, FlightList, OrderList, ChargebackList, UserList, AccountList);
        return result;
    } else {
        if(AIR_LIFE_DEBUG_MODE){
            /*Debug Code Here*/

        }
        else {
            /*TEST Code Here*/

            auto* pWindows = new testWindows();
            pWindows->show();
            int result = QApplication::exec();
            return result;
        }
    }
}


void init(std::vector<COMPONENT::Area *> &areaList,
          std::vector<COMPONENT::Airplane *> &airplaneList,
          std::vector<COMPONENT::Flight *> &flightList,
          std::vector<COMPONENT::Orders *> &orderList,
          std::vector<COMPONENT::Chargebacks *> &chargebackList,
          std::vector<COMPONENT::User *> &userList,
          std::vector<COMPONENT::Account *> &accountList) {
    auto* initialHandler = new airLifeHandler::InitialHandler();
    initialHandler->putVector(areaList, airplaneList, flightList, orderList, chargebackList, userList, accountList);
    initialHandler->runTask();
    if(initialHandler->getTaskStatus()) delete initialHandler;
}
void save(std::vector<COMPONENT::Area *> &areaList,
          std::vector<COMPONENT::Airplane *> &airplaneList,
          std::vector<COMPONENT::Flight *> &flightList,
          std::vector<COMPONENT::Orders *> &orderList,
          std::vector<COMPONENT::Chargebacks *> &chargebackList,
          std::vector<COMPONENT::User *> &userList,
          std::vector<COMPONENT::Account *> &accountList) {
    auto* updateHandler = new airLifeHandler::UpdateHandler();
    updateHandler->putClazzList(areaList, airplaneList, flightList, orderList, chargebackList, userList, accountList);
    updateHandler->runTask();
    if(updateHandler->getTaskStatus()) delete updateHandler;
    COMPONENT::synchronization(areaList, airplaneList, flightList, orderList, chargebackList, userList, accountList);
}
//
// Created by f2561 on 24-5-23.
//

#ifndef AIRLIFE_INITIALHANDLER_H
#define AIRLIFE_INITIALHANDLER_H
#include "ClassWorkHandler.h"
#include "../Base/component.h"
#include <iostream>
#include <vector>
namespace airLifeHandler {

    class InitialHandler
        :public ClassWorkHandler{
        std::vector<std::string> InitialFileNameList;
        std::string directory;
        ReadFileHandler *AreaData{},
                        *AirplaneData{},
                        *FlightData{},
                        *OrderData{},
                        *ChargebackData{},
                        *UserData{},
                        *AccountData{};
        std::vector<COMPONENT::Area *> AreaList;
        std::vector<COMPONENT::Airplane *> AirplaneList;
        std::vector<COMPONENT::Flight *> FlightList;
        std::vector<COMPONENT::Orders *> OrderList;
        std::vector<COMPONENT::Chargebacks *> ChargebackList;
        std::vector<COMPONENT::User *> UserList;
        std::vector<COMPONENT::Account *> AccountList;

    public:
        InitialHandler();
        void initDataArray() {}
        bool initTaskRun(std::string file) override;
        void putVector(
                std::vector<COMPONENT::Area*> &areaList,
                std::vector<COMPONENT::Airplane*> &airplaneList,
                std::vector<COMPONENT::Flight*> &flightList,
                std::vector<COMPONENT::Orders*> &orderList,
                std::vector<COMPONENT::Chargebacks*> &chargebackList,
                std::vector<COMPONENT::User*> &userList,
                std::vector<COMPONENT::Account*> &accountList
        );

        bool isAllReady(){
            return
                    (AreaData != nullptr) &&
                    (AirplaneData != nullptr) &&
                    (FlightData != nullptr) &&
                    (OrderData != nullptr) &&
                    (ChargebackData != nullptr) &&
                    (UserData != nullptr) &&
                    (AccountData != nullptr);

        }
        void runTask() override;
        void ReadAndUpVector();
    };

} // airLifeHandler

#endif //AIRLIFE_INITIALHANDLER_H

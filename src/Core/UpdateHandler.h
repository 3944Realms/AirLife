//
// Created by f2561 on 24-5-24.
//

#ifndef AIRLIFE_UPDATEHANDLER_H
#define AIRLIFE_UPDATEHANDLER_H
#include "ClassWorkHandler.h"
#include "WriteFileHandler.h"

namespace airLifeHandler {

    class UpdateHandler
            :public ClassWorkHandler {
        std::vector<std::string> UpdateFileNameList;
        std::string directory;
        WriteFileHandler *AreaData{},
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
        UpdateHandler();
        void putClazzList(
                    std::vector<COMPONENT::Area*> &areaList,
                    std::vector<COMPONENT::Airplane*> &airplaneList,
                    std::vector<COMPONENT::Flight*> &flightList,
                    std::vector<COMPONENT::Orders*> &orderList,
                    std::vector<COMPONENT::Chargebacks*> &chargebackList,
                    std::vector<COMPONENT::User*> &userList,
                    std::vector<COMPONENT::Account*> &accountList
                );
        bool initTaskRun(std::string file) override;
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
        void WriteAndDownVector();
    };

} // airLifeHandler

#endif //AIRLIFE_UPDATEHANDLER_H

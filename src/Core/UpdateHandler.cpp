//
// Created by f2561 on 24-5-24.
//

#include "UpdateHandler.h"

namespace airLifeHandler {
    UpdateHandler::UpdateHandler() {
        directory = std::string("airLifeData");
        UpdateFileNameList.emplace_back("AreaData.dat");
        UpdateFileNameList.emplace_back("FlightData.dat");
        UpdateFileNameList.emplace_back("OrderData.dat");
        UpdateFileNameList.emplace_back("ChargebackData.dat");
        UpdateFileNameList.emplace_back("UseData.dat");
        UpdateFileNameList.emplace_back("AccountData.dat");

        InitFile(UpdateFileNameList, directory);
    }

    bool UpdateHandler::initTaskRun(std::string file) {
        std::string pathFile = directory + "\\" + file;
        if(file == "AreaData.dat")
            AreaData = new WriteFileHandler(pathFile, DataType::AREA);
        else if(file == "AirplaneData.dat")
            AirplaneData = new WriteFileHandler(pathFile, DataType::AIRPLANE);
        else if(file == "FlightData.dat")
            FlightData = new WriteFileHandler(pathFile, DataType::FLIGHT);
        else if(file == "OrderData.dat")
            OrderData = new WriteFileHandler(pathFile, DataType::ORDER);
        else if(file == "ChargebackData.dat")
            ChargebackData = new WriteFileHandler(pathFile, DataType::CHARGEBACK);
        else if(file == "UserData.dat")
            UserData = new WriteFileHandler(pathFile, DataType::USER);
        else if(file == "AccountData.dat")
            AccountData = new WriteFileHandler(pathFile, DataType::ACCOUNT);
        else{
            return false;
        }
        return true;
    }

    void UpdateHandler::runTask() {
        if(!isAllReady()) {
            std::cout << "[*]" << "Not Ready\n";
            return;
        }
        WriteAndDownVector();
    }

    void UpdateHandler::putClazzList(std::vector<COMPONENT::Area *> &areaList,
                                     std::vector<COMPONENT::Airplane *> &airplaneList,
                                     std::vector<COMPONENT::Flight *> &flightList,
                                     std::vector<COMPONENT::Orders *> &orderList,
                                     std::vector<COMPONENT::Chargebacks *> &chargebackList,
                                     std::vector<COMPONENT::User *> &userList,
                                     std::vector<COMPONENT::Account *> &accountList) {
        AreaList = areaList;
        AirplaneList = airplaneList;
        FlightList = flightList;
        OrderList = orderList;
        ChargebackList = chargebackList;
        UserList = userList;
        AccountList = accountList;
    }

    void UpdateHandler::WriteAndDownVector() {
        std::vector<std::vector<char>> AreaDest;
        std::vector<std::vector<char>> AirplaneDest;
        std::vector<std::vector<char>> FlightDest;
        std::vector<std::vector<char>> OrderDest;
        std::vector<std::vector<char>> ChargebackDest;
        std::vector<std::vector<char>> UserDest;
        std::vector<std::vector<char>> AccountDest;

        AreaDest.reserve(AreaList.size());
        AirplaneDest.reserve(AirplaneList.size());
        FlightDest.reserve(FlightList.size());
        OrderDest.reserve(OrderList.size());
        ChargebackDest.reserve(ChargebackList.size());
        UserDest.reserve(UserList.size());
        AccountDest.reserve(AccountList.size());

        for(auto l : AreaList) {
            AreaDest.push_back(l->serialize());
        }

        for(auto l : AirplaneList) {
            AirplaneDest.push_back(l->serialize());
        }

        for(auto l : FlightList) {
            FlightDest.push_back(l->serialize());
        }

        for(auto l : OrderList) {
            OrderDest.push_back(l->serialize());
        }

        for(auto l : ChargebackList) {
            ChargebackDest.push_back(l->serialize());
        }

        for(auto l : UserList) {
            UserDest.push_back(l->serialize());
        }

        for(auto l : AccountList) {
            AccountDest.push_back(l->serialize());
        }

        AreaData->writeAll(AreaDest, COMPONENT::AreaBlockSize);
        AirplaneData->writeAll(AirplaneDest, COMPONENT::AccountBlockSize);
        FlightData->writeAll(FlightDest, COMPONENT::FlightBlockSize);
        OrderData->writeAll(OrderDest, COMPONENT::OrderBlockSize);
        ChargebackData->writeAll(ChargebackDest, COMPONENT::ChargebacksBlockSize);
        UserData->writeAll(UserDest, COMPONENT::UserBlockSize);
        AccountData->writeAll(AccountDest, COMPONENT::AccountBlockSize);
        taskSuccessful = true;
    }

} // airLifeHandler
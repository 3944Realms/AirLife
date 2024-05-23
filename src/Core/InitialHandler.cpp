//
// Created by f2561 on 24-5-23.
//

#include "InitialHandler.h"

namespace airLifeHandler {
    InitialHandler::InitialHandler() {
        directory = std::string("airLifeData");
        InitialFileNameList.emplace_back("AreaData.dat");
        InitialFileNameList.emplace_back("AirplaneData.dat");
        InitialFileNameList.emplace_back("FlightData.dat");
        InitialFileNameList.emplace_back("OrderData.dat");
        InitialFileNameList.emplace_back("ChargebackData.dat");
        InitialFileNameList.emplace_back("UserData.dat");
        InitialFileNameList.emplace_back("AccountData.dat");
    /*
     * DataType  的读入
     * USER -> UUID ReadHandler(file, USER)
     *
     */
        // init()[Build Object{
        // DataFile: Directory: {AirLifeData}
        // File:
        //      AreaData.dat, Airplane.dat,
        //      Flight.dat, Order.dat,
        //      Chargeback.dat, User.dat,
        //      Account.dat[未实现]}]
        //
        //      ->
        // Area(UUID) ,
        // Airplane(UUID) ,
        // Flight(UUID)[ Airplane , Area ] ,
        // Order(OrderUUID)[Flight],
        // Chargeback(ChargebackUUID) ,
        // User(UUID)[
        //              Orders(OrderUUID)[Flight] ,
        //              Chargebacks(ChargeBackUUID)[Order]
        //            ];
        // Account(){User}

        //

    }

    bool InitialHandler::initTaskRun(std::string file) {
        std::string pathFile = directory + "/" + file;
        if(file == "AreaData.dat")
            AreaData = new ReadFileHandler(pathFile, DataType::AREA);
        else if(file == "AirplaneData.dat")
            AirplaneData = new ReadFileHandler(pathFile, DataType::AIRPLANE);
        else if(file == "FlightData.dat")
            FlightData = new ReadFileHandler(pathFile, DataType::FLIGHT);
        else if(file == "OrderData.dat")
            OrderData = new ReadFileHandler(pathFile, DataType::ORDER);
        else if(file == "ChargebackData.dat")
            ChargebackData = new ReadFileHandler(pathFile, DataType::CHARGEBACK);
        else if(file == "UserData.dat")
            UserData = new ReadFileHandler(pathFile, DataType::USER);
        else if(file == "AccountData.dat")
            AccountData = new ReadFileHandler(pathFile, DataType::ACCOUNT);
        else{
            return false;
        }
        return true;
    }

    void InitialHandler::runTask() {
        if(!isAllReady()) {
            std::cout << "[*]" << "Not Ready\n";
            return;
        }
        ReadAndUpVector();
    }

    void InitialHandler::putVector(std::vector<COMPONENT::Area *> &areaList,
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

    void InitialHandler::ReadAndUpVector() {
        std::vector<std::vector<char>> AreaDest;
        std::vector<std::vector<char>> AirplaneDest;
        std::vector<std::vector<char>> FlightDest;
        std::vector<std::vector<char>> OrderDest;
        std::vector<std::vector<char>> ChargebackDest;
        std::vector<std::vector<char>> UserDest;
        std::vector<std::vector<char>> AccountDest;
        AreaData->readAll(AreaDest,COMPONENT::AreaBlockSize);
        AirplaneData->readAll(AirplaneDest, COMPONENT::AirplaneBlockSize);
        FlightData->readAll(FlightDest, COMPONENT::FlightBlockSize);
        OrderData->readAll(OrderDest, COMPONENT::OrderBlockSize);
        ChargebackData->readAll(ChargebackDest, COMPONENT::ChargebacksBlockSize);
        UserData->readAll(UserDest, COMPONENT::UserBlockSize);
        AccountData->readAll(AccountDest, COMPONENT::AccountBlockSize);
        for(const auto& l : AreaDest){
            AreaList.push_back(COMPONENT::Area::deserialize(l));
        }
        for(const auto& l : AirplaneDest){
            AirplaneList.push_back(COMPONENT::Airplane::deserialize(l));
        }
        for(const auto& l : FlightDest){
            FlightList.push_back(COMPONENT::Flight::deserialize(l));
        }
        for(const auto& l : OrderDest){
            OrderList.push_back(COMPONENT::Orders::deserialize(l));
        }
        for(const auto& l : ChargebackDest){
            ChargebackList.push_back(COMPONENT::Chargebacks::deserialize(l));
        }
        for(const auto& l : UserDest){
            UserList.push_back(COMPONENT::User::deserialize(l));
        }
        for(const auto& l : AccountDest){
            AccountList.push_back(COMPONENT::Account::deserialize(l));
        }
    }
} // airLifeHandler
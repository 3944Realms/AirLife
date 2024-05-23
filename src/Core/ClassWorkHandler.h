//
// Created by f2561 on 24-5-21.
//

#ifndef AIRLIFE_CLASSWORKHANDLER_H
#define AIRLIFE_CLASSWORKHANDLER_H
#include "ReadFileHandler.h"
#include <fstream>
#include <iostream>

namespace airLifeHandler {

    class ClassWorkHandler {
        bool isInit;
    public:
        void InitFile(const std::vector<std::string>& files, const std::string& filesPath);
        static bool IsFileExist(const std::string& fileName, const std::string& filePath);
        static bool CreateFile(const std::string& fileName, const std::string& filePath);
        ClassWorkHandler();//Area(String) 、 Airplane(String, UShort, UShort)  Flight(string, Airplane, Area[2], Date, Time, bool)
        virtual bool initTaskRun(std::string file) = 0;
        virtual void runTask() = 0;
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


    };
    //序列化对象的内容都会被写入到二进制数据流中, 1.同步问题（Sync）[]
    //操作

} // airLifeHandler

#endif //AIRLIFE_CLASSWORKHANDLER_H

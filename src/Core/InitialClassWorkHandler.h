//
// Created by f2561 on 24-5-21.
//

#ifndef AIRLIFE_INITIALCLASSWORKHANDLER_H
#define AIRLIFE_INITIALCLASSWORKHANDLER_H
#include "ReadFileHandler.h"

namespace airLifeHandler {

    class InitialClassWorkHandler {
        bool isInit;

    public:
        InitialClassWorkHandler();//Area(String) 、 Airplane(String, UShort, UShort)  Flight(string, Airplane, Area[2], Date, Time, bool)
        // init()[Build Object{DataFile: Directory: {AirLifeData}  File: AreaData.dat, Airplane.dat, Flight.dat, User.dat, Account.dat[未实现]}] ->
        // Area(UUID) ,
        // Airplane(UUID) ,
        // Flight(UUID)[ Airplane , Area ] ,
        // User(UUID)[
        //              Orders(OrderUUID)[User , Flight] ,
        //              Chargebacks(ChargeBackUUID)[User , Order]
        //            ];
        // Account(){User}

        //
    };
    //序列化对象的内容都会被写入到二进制数据流中, 1.同步问题（Sync）[]
    //操作

} // airLifeHandler

#endif //AIRLIFE_INITIALCLASSWORKHANDLER_H

//
// Created by f2561 on 24-5-21.
//

#ifndef AIRLIFE_INITIALCLASSWORKHANDLER_H
#define AIRLIFE_INITIALCLASSWORKHANDLER_H

namespace airLifeHandler {

    class InitialClassWorkHandler {
        bool isInit;
    public:
        InitialClassWorkHandler();//Area(String) 、 Airplane(String, UShort, UShort)  Flight(string, Airplane, Area[2], Date, Time, bool)
    };
    //序列化对象的内容都会被写入到二进制数据流中, 1.同步问题（Sync）[]

} // airLifeHandler

#endif //AIRLIFE_INITIALCLASSWORKHANDLER_H

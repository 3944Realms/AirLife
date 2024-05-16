//
// Created by f2561 on 24-5-15.
//

#ifndef AIRLIFE_READFILEHANDLER_H
#define AIRLIFE_READFILEHANDLER_H
#include <iostream>
#include <fstream>
#include <vector>


namespace airLifeHandler {
    enum DataType{
        USER,
        AIRPLANE,
        ORDER,
        CHARGEBACK,
        FLIGHT,
        AREA,
        ACCOUNT,
        DATA,
        TIME,
        UNKNOWN
    };
    enum ResultStatus {
        WAITING,
        RUNNING,
        SUCCESSFUL,
        FAILED
    };
    class ReadFileHandler {
         std::fstream readOut;
         DataType dataType;
         ResultStatus resultStatus;
    public:
        ReadFileHandler(const std::string& filePath, DataType readDataType);
        ResultStatus getStatue() {return resultStatus;}
        DataType getReadDataType() {return dataType;}
        template<class Clazz> void readNext(Clazz &clazz);
        template<class Clazz> std::vector<Clazz> readAll(Clazz clazz);

        template<class Clazz> void readFromDesignatedNumber(Clazz &clazz, int Number);
    };

} // airLifeHandler

#endif //AIRLIFE_READFILEHANDLER_H

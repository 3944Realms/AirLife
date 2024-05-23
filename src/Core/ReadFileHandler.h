//
// Created by f2561 on 24-5-15.
//

#ifndef AIRLIFE_READFILEHANDLER_H
#define AIRLIFE_READFILEHANDLER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "../Base/component.h"


namespace airLifeHandler {

    class ReadFileHandler {
         std::fstream readOut;
         DataType dataType;
         ResultStatus resultStatus;
    public:
        ReadFileHandler(const std::string& filePath, DataType readDataType);
        ResultStatus getStatue() {return resultStatus;}
        DataType getReadDataType() {return dataType;}
        size_t getBlockSize() {
            switch (dataType) {
                case USER:
                    return COMPONENT::UserBlockSize;
                case AIRPLANE:
                    return COMPONENT::AirplaneBlockSize;
                case ORDER:
                    return COMPONENT::OrderBlockSize;
                case CHARGEBACK:
                    return COMPONENT::ChargebacksBlockSize;
                case FLIGHT:
                    return COMPONENT::FlightBlockSize;
                case AREA:
                    return COMPONENT::AreaBlockSize;
                case ACCOUNT:
                    return COMPONENT::AccountBlockSize;
                case DATE:
                    return sizeof(COMPONENT::Date);
                case TIME:
                    return sizeof(COMPONENT::Date::Time);
                case UNKNOWN_DATA_TYPE:
                    return 0;
            }
        }
        template<class Clazz> void readNext(Clazz &clazz);
        void readNext(std::vector<char> &dest, size_t size);
        template<class Clazz> std::vector<Clazz> readAll(Clazz clazz);
        void readAll(std::vector<std::vector<char>> &destList, size_t blockSize);
        template<class Clazz> void readFromDesignatedNumber(Clazz &clazz, int Number);
        void readFromDesignatedNumber(std::vector<char> &targetDest, size_t blockSize, int Number);
        ~ReadFileHandler() { if(readOut.is_open())readOut.close(); };
    };

} // airLifeHandler

#endif //AIRLIFE_READFILEHANDLER_H

//
// Created by f2561 on 24-5-15.
//

#include "ReadFileHandler.h"

namespace airLifeHandler {
    ReadFileHandler::ReadFileHandler(const std::string& filePath, DataType readDataType) {
        using namespace std;
        dataType = readDataType;
        readOut.open(filePath, ios::binary | ios::out);
        if(readOut.is_open()) resultStatus = ResultStatus::WAITING;
        else resultStatus = ResultStatus::FAILED;
    }

    template<class Clazz>
    void ReadFileHandler::readFromDesignatedNumber(Clazz &clazz, int Number) {
        if(Number <= 0) return;
        resultStatus = ResultStatus::RUNNING;
        int clazzSize = sizeof(clazz);
        readOut.seekg(clazzSize*(Number - 1));
        if(readOut.read(reinterpret_cast<char *>(&clazz),clazzSize)) resultStatus = ResultStatus::WAITING;
        else resultStatus = ResultStatus::SUCCESSFUL;
    }

    template<class Clazz>
    std::vector<Clazz> ReadFileHandler::readAll(Clazz clazz) {
        using namespace std;
        vector<Clazz> clazzList;
        resultStatus = ResultStatus::RUNNING;
        while(readOut.read(reinterpret_cast<char*>(&clazz),sizeof(clazz))){
            clazzList.push_back(clazz);
        }
        resultStatus = ResultStatus::SUCCESSFUL;
        return clazzList;
    }

    template<class Clazz>
    void ReadFileHandler::readNext(Clazz &clazz) {
        resultStatus = ResultStatus::RUNNING;
        if(readOut.read(reinterpret_cast<char*>(&clazz),sizeof(clazz))) resultStatus = ResultStatus::WAITING;
        else resultStatus = ResultStatus::SUCCESSFUL;
    }
} // airLifeHandler
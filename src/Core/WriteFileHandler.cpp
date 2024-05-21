//
// Created by f2561 on 24-5-15.
//

#include "WriteFileHandler.h"

namespace airLifeHandler {

    WriteFileHandler::WriteFileHandler(const std::string &filePath, DataType writeDataType, std::ios::openmode openMode) {
        using namespace std;
        dataType = writeDataType;
        writeOn.open(filePath, openMode);
        if(writeOn.is_open()) resultStatus = ResultStatus::INITIAL;
        else resultStatus = ResultStatus::INITIAL_FAILED;
    }

    void WriteFileHandler::writeNext(std::vector<char> &target, size_t size) {
        resultStatus = ResultStatus::RUNNING;
        if(target.empty()) {
            resultStatus = ResultStatus::FAILED;
            return;
        }
        writeOn.write(target.data(),(int)size);
        resultStatus = ResultStatus::SUCCESSFUL;
    }

    void WriteFileHandler::writeAll(std::vector<std::vector<char>> &targetList, size_t size) {
        resultStatus = ResultStatus::RUNNING;
        if(targetList.empty()) {
            resultStatus = ResultStatus::FAILED;
            return;
        }
        for(const auto & i : targetList) {
            resultStatus = ResultStatus::RUNNING;
            if(i.empty()) {
                resultStatus = ResultStatus::FAILED;
                return;
            }
            writeOn.write(i.data(), (int)size);
        }
        resultStatus = ResultStatus::SUCCESSFUL;
    }

} // airLifeHandler
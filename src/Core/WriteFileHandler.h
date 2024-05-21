//
// Created by f2561 on 24-5-15.
//

#ifndef AIRLIFE_WRITEFILEHANDLER_H
#define AIRLIFE_WRITEFILEHANDLER_H
#include <fstream>
#include "../Base/component.h"


namespace airLifeHandler {

    class WriteFileHandler {
        std::ofstream writeOn;
        DataType dataType;
        ResultStatus resultStatus;
    public:
        WriteFileHandler(const std::string& filePath, DataType writeDataType, std::ios::openmode openMode);
        ResultStatus getStatue() {return resultStatus;}
        DataType getReadDataType() {return dataType;}
        void writeNext(std::vector<char>  &target, size_t size);
        void writeAll(std::vector<std::vector<char>> &targetList, size_t size);
        ~WriteFileHandler() { if(writeOn.is_open()) writeOn.close(); }
    };

} // airLifeHandler

#endif //AIRLIFE_WRITEFILEHANDLER_H

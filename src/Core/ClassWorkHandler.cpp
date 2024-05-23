//
// Created by f2561 on 24-5-21.
//

#include "ClassWorkHandler.h"

namespace airLifeHandler {
    ClassWorkHandler::ClassWorkHandler() : isInit(false) {}
    void ClassWorkHandler::InitFile(const std::vector<std::string>& files, const std::string& filesPath) {
        for (const auto& file: files) {
            if(!IsFileExist(file, filesPath)){
                std::cout << "[*]" << file <<" is not existed at '" << filesPath << "' Directory\n";
                if(!CreateFile(file, filesPath)){
                    std::cerr << "[x]" << file << " can't be created at '" << filesPath << "' Directory\n";
                    return;
                }
            }else {
                std::cout << "[*]" << "Find " << file << " at '" << filesPath << "' Directory\n";
                if(initTaskRun(file)) std::cout << "[*]" << "Run Task Successful !\n";
                else{
                    std::cerr << "[x]" << "Run Task Failed !\n";
                    return;
                }
            }
        }
    }

    bool ClassWorkHandler::IsFileExist(const std::string& fileName, const std::string& filePath) {
        std::ifstream file(filePath + "/" + fileName);
        bool status = file.is_open();
        file.close();
        return status;
    }

    bool ClassWorkHandler::CreateFile(const std::string& fileName, const std::string& filePath) {
        std::ofstream file(filePath + "/" + fileName);
        bool status = file.is_open();
        file.close();
        return status;
    }



} // airLifeHandler
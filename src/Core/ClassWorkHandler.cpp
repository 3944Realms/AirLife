//
// Created by f2561 on 24-5-21.
//

#include "ClassWorkHandler.h"
//#include "experimental/filesystem"
#include <windows.h>

namespace airLifeHandler {
    ClassWorkHandler::ClassWorkHandler() : isInit(false) , taskSuccessful(false) {}
    void ClassWorkHandler::InitFile(const std::vector<std::string>& files, const std::string& filesPath) {
//        std::experimental::filesystem::v1::__cxx11::path dir("airLifeData");
//        bool fileCreateStatus = std::experimental::filesystem::v1::create_directory(dir);
        bool fileCreateStatus = CreateDirectory("airLifeData", nullptr);
        std::cout << "[INFO] " << (fileCreateStatus ? "Directory created successfully." : "Failed to create directory. \n") << std::endl;
        for (const auto& file: files) {
            if(!IsFileExist(file, filesPath)){
                std::cout << "[*] " << file <<" is not existed at '" << filesPath << "' Directory. \n";
                if(!CCreateFile(file, filesPath)){
                    std::cerr << "[x] " << file << " can't be created at '" << filesPath << "' Directory. \n";
                    return;
                }
            }else {
                std::cout << "[*] " << "Find " << file << " at '" << filesPath << "' Directory. \n";
                if(initTaskRun(file)) {
                    std::cout << "[*] " << "Run Task Successful !\n";
                    isInit = true;
                }
                else{
                    std::cerr << "[x] " << "Run Task Failed !\n";
                    return;
                }
            }
        }
    }

    bool ClassWorkHandler::IsFileExist(const std::string& fileName, const std::string& filePath) {
        std::ifstream file(filePath + "\\" + fileName);
        bool status = file.is_open();
        file.close();
        return status;
    }

    bool ClassWorkHandler::CCreateFile(const std::string& fileName, const std::string& filePath) {
        std::ofstream file(filePath + "\\" + fileName);
        bool status = file.is_open();
        file.close();
        return status;
    }



} // airLifeHandler
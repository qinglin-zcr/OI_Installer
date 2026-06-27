#include "installer.h"
#include "logger.h"
#include "filesystem.h"

namespace fs=std::filesystem;

void Installer::run(){
    Logger::info("Installer started");

    if(!m_config.load("config/install.json")){
        Logger::info("Fail to load config file.");
        return;
    }

    Logger::info("Install Path: "+m_config.installPath());
    fs::create_directories(m_config.installPath());

    for(auto&pkg:m_config.packages()){
        fs::path src="packages";src/=pkg;
        fs::path dst=m_config.installPath();dst/=pkg;
        Logger::info("Installing "+pkg);
        FileSystem::copyDirectory(src,dst);
    }
}

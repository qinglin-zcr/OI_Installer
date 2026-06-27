#include "logger.h"
#include "config.h"
#include "json.hpp"
#include <fstream>
using json=nlohmann::json;
bool Config::load(const std::string&path){
    std::ifstream fin(path);
    if(!fin){
        Logger::error("Cannot open config.");
        return 0;
    }
    try{
        json j;fin>>j;
        m_installPath=j.at("installPath");
        m_packages=j.at("packages").get<std::vector<std::string>>();
        return 1;
    }
    catch(const std::exception&e){
        Logger::error(e.what());
        return 0;
    }
}
const std::string& Config::installPath()const{
    return m_installPath;
}
const std::vector<std::string>& Config::packages()const{
    return m_packages;
}
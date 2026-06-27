#pragma once
#include <string>
#include <vector>
class Config{
private:    
    std::string m_installPath;
    std::vector<std::string>m_packages;
public:
    bool load(const std::string&path);
    const std::string& installPath()const;
    const std::vector<std::string>& packages()const;
};
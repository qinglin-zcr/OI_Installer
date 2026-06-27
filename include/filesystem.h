#pragma once
#include <filesystem>
class FileSystem{
public:
    static bool copyDirectory(const std::filesystem::path&src,const std::filesystem::path&dst);
};
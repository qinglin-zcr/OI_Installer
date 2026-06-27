#include "filesystem.h"
#include "logger.h"
namespace fs=std::filesystem;
bool FileSystem::copyDirectory(const fs::path&src,const fs::path&dst){
    try{
        fs::create_directories(dst);
        fs::copy(src,dst,fs::copy_options::recursive|fs::copy_options::overwrite_existing);
        return 1;
    }catch(const std::exception&e){
        Logger::error(e.what());
        return 0;
    }
}
#ifndef FETCHPP_LOGO_LOADER_HPP
#define FETCHPP_LOGO_LOADER_HPP

#include <fstream>
#include <string>

inline std::string LoadCustomLogo(const std::string& path){
    std::ifstream file(path);
    if(!file){
        return "Could not read file at: " + path;
    }

    std::string line, ret;
    while(std::getline(file, line)){
        ret += line + '\n';
    }

    file.close();

    return ret;
}

#endif

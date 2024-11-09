#include "fetcher.hpp"
#include "color.hpp"
#include "assets.hpp"

#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>
#include <sys/utsname.h>

#define NL '\n'

void Fetcher::FetchData(){
    struct utsname linuxInfo;
    if(uname(&linuxInfo) != 0){
        throw std::runtime_error("Could not get system info!");
    }

    std::string os = FindLineInFile("/etc/os-release", "PRETTY_NAME");
    auto pos = os.find('=');
    if(pos != std::string::npos){
        os = os.substr(pos + 1);
        if(os.front() == '"' && os.back() == '"'){
            os = os.substr(1, os.size() - 2);
        }
    }

    std::string ID = FindLineInFile("/etc/os-release", "ID");
    pos = ID.find('=');
    if(pos != std::string::npos){
        ID = ID.substr(pos + 1);
        if(ID.front() == '"' && ID.back() == '"'){
            ID = ID.substr(1, ID.size() - 2);
        }
    }

    std::string pkgsCmd;
    std::string pkgCount("Packages: ");
    auto it = packageCmd.find(ID);
    if(it != packageCmd.end()){
        pkgsCmd = it->second;
    }
    else{
        pkgsCmd = "";
    }

    std::string hostname("Hostname: ");
    std::string kernel("Kernel: ");

    os.insert(0, "OS: ");
    hostname.append(linuxInfo.nodename);
    kernel.append(linuxInfo.release);

    m_infoBuf = os + NL +
                hostname + NL +
                kernel + NL;

    if(!pkgsCmd.empty()){
        pkgCount.append(ExecCmd(pkgsCmd));
        m_infoBuf.append(pkgCount + NL);
    }
}

void Fetcher::Draw(const std::string& logo, const std::string& logoColor){
    std::cout << logoColor << logo << ansiColor.at(DEFAULT) << NL;
    std::cout << m_infoBuf << NL;
}

std::string Fetcher::FindLineInFile(const std::string& path, const std::string& target){
    std::ifstream file(path);
    if(!file){
        std::cerr << "Could not opent file: " << path << NL;
        return "";
    }

    std::string ret{};
    if(target.empty()){
        std::getline(file, ret);
        return ret;
    }

    std::string line{};
    while(std::getline(file, line)){
        if(line.find(target) == 0){
            ret = line;
        }
    }

    file.close();

    return ret;
}

std::string Fetcher::ExecCmd(const std::string& cmd){
    std::array<char, 128> buffer{};
    std::string res{};

    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);

    if(!pipe){
        throw std::runtime_error("popen() failed");
    }

    while(fgets(buffer.data(), static_cast<int>(buffer.size()), pipe.get()) != nullptr){
        res += buffer.data();
    }

    RemoveWhitespace(&res);
    return res;
}

void Fetcher::RemoveWhitespace(std::string* str){
    str->erase(std::remove_if(str->begin(), str->end(), ::isspace), str->end());
}

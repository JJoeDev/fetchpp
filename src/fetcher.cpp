#include "fetcher.hpp"

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

    std::string packages = ExecCmd("xbps-query -l | wc -l");
    std::string hostname = linuxInfo.nodename;
    std::string kernel = linuxInfo.release;
    
    RemoveWhitespace(&packages);

    os.insert(0, "OS: ");
    packages.insert(0, "Packages: ");
    hostname.insert(0, "Hostname: ");
    kernel.insert(0, "Kernel: ");

    m_infoBuf = os + NL +
                packages + NL +
                hostname + NL +
                kernel + NL;
}

void Fetcher::Draw(const std::string& logo){
    std::cout << ansiColor.at(Color::GREEN) << logo << ansiColor.at(Color::DEFAULT) << '\n';
    std::cout << m_infoBuf << '\n';
}

std::string Fetcher::FindLineInFile(const std::string& path, const std::string& target){
    std::ifstream file(path);
    if(!file){
        std::cerr << "Could not opent file: " << path << '\n';
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

    return res;
}

void Fetcher::RemoveWhitespace(std::string* str){
    str->erase(std::remove_if(str->begin(), str->end(), ::isspace), str->end());
}

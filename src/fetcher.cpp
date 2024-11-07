#include "fetcher.hpp"

#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>

void Fetcher::FetchData(){
    GetOSName();

    m_packages = ExecCmd("xbps-query -l | wc -l");
    m_hostname = ExecCmd("cat /etc/hostname");
    
    RemoveWhitespace(&m_packages);
    RemoveWhitespace(&m_hostname);
}

void Fetcher::Draw(const std::string& logo){
    std::cout << ansiColor.at(Color::GREEN) << logo << ansiColor.at(Color::DEFAULT) << '\n';
    std::cout << "OS: " << m_OS << '\n';
    std::cout << "ID: " << m_ID << '\n';
    std::cout << "Hostname: " << m_hostname << '\n';
    std::cout << "Packages: " << m_packages << '\n';
    std::cout << "CPU: " << m_cpu << '\n';
}

void Fetcher::GetOSName(){
    std::ifstream os_release("/etc/os-release");
    if(!os_release){
        std::cerr << "Could not find os-release file in /etc/os-release\n";
        return;
    }

    std::string line;
    while(std::getline(os_release, line)){
        if(line.find("PRETTY_NAME=") == 0){
            auto pos = line.find('=');
            if(pos != std::string::npos){
                m_OS = line.substr(pos + 1);
                if(m_OS.front() == '"' && m_OS.back() == '"'){
                    m_OS = m_OS.substr(1, m_OS.size() - 2);
                }
            }
        }
        else if(line.find("ID=") == 0){
            auto pos = line.find('=');
            if(pos != std::string::npos){
                m_ID = line.substr(pos + 1);
                if(m_ID.front() == '"' && m_ID.back() == '"'){
                    m_ID = m_ID.substr(1, m_ID.size() - 2);
                }
            }
        }
    }
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

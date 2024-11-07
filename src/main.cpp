#include <iostream>

#include <getopt.h>
#include <string>

#include "assets.hpp"
#include "logos-builtin.hpp"

int main(int argc, char** argv){
    std::string optstr;
    int option = 0;

    while((option = getopt(argc, argv, ":hvl:")) != -1){
        switch(option){
            case 'h':
                std::cout << HelpMessageStr;
                return 0;
            case 'v':
                std::cout << fetchppVersionStr;
                return 0;
            case 'l':
                if(auto it{LogosStr.find(optarg)}; it != LogosStr.end()){
                    std::cout << it->second << '\n';
                }
                break;
            case ':':
                std::cout << "Option requires a value\n";
                return 0;
            case '?':
                std::cout << "Unknown option: " << std::string(optarg) << " | Use -h or --help for argument list\n";
                return 0;
            default:
                std::cout << "Unknown!\n";
                return 0;
        }
    }

    return 0;
}
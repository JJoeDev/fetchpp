#include <iostream>

#include <getopt.h>
#include <string>

#include "color.hpp"
#include "fetcher.hpp"
#include "logoLoader.hpp"
#include "assets.hpp"
#include "logos-builtin.hpp"

int main(int argc, char** argv){
    std::string logo;
    std::string logoColor = DEFAULT;
    int option = 0;

    while((option = getopt(argc, argv, ":hvl:p:c:")) != -1){
        switch(option){
            case 'h':
                std::cout << HelpMessageStr;
                return 0;
            case 'v':
                std::cout << fetchppVersionStr;
                return 0;
            case 'l':
                if(auto it{LogosStr.find(optarg)}; it != LogosStr.end()){
                    logo = it->second;
                }
                else{
                    logo = "\nLogo does not exist...\n";
                }
                break;
            case 'p':
                logo = LoadCustomLogo(optarg);
                break;
            case 'c':
                if(auto it{ansiColor.find(optarg)}; it != ansiColor.end()){
                    logoColor = optarg;
                }
                else{
                    std::cout << "Color not in map\n";
                    logoColor = DEFAULT;
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

    Fetcher fetcher;
    fetcher.FetchData();

    fetcher.Draw(logo, logoColor);

    return 0;
}

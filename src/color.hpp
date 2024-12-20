#ifndef FETCHPP_COLOR_HPP
#define FETCHPP_COLOR_HPP

#include <unordered_map>
#include <string>

#define BLACK "BLACK"
#define RED "RED"
#define GREEN "GREEN"
#define YELLOW "YELLOW"
#define BLUE "BLUE"
#define MAGENTA "MAGENTA"
#define CYAN "CYAN"
#define WHITE "WHITE"
#define DEFAULT "DEFAULT"

const static std::unordered_map<std::string, std::string> ansiColor = {
    { "BLACK",   "\033[1;30m" },
    { "RED",     "\033[1;31m" },
    { "GREEN",   "\033[1;32m" },
    { "YELLOW",  "\033[1;33m" },
    { "BLUE",    "\033[1;34m" },
    { "MAGENTA", "\033[1;35m" },
    { "CYAN",    "\033[1;36m" },
    { "WHITE",   "\033[1;37m" },
    { "DEFAULT", "\033[0m"    },
};

#endif

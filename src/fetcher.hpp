#ifndef FETCHPP_FETCHER_HPP
#define FETCHPP_FETCHER_HPP

#include <string>
#include <unordered_map>

enum class Color{
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    DEFAULT,  
};

const static std::unordered_map<Color, const char*> ansiColor = {
    { Color::BLACK,   "\033[1;30m" },
    { Color::RED,     "\033[1;31m" },
    { Color::GREEN,   "\033[1;32m" },
    { Color::YELLOW,  "\033[1;33m" },
    { Color::BLUE,    "\033[1;34m" },
    { Color::MAGENTA, "\033[1;35m" },
    { Color::CYAN,    "\033[1;36m" },
    { Color::WHITE,   "\033[1;37m" },
    { Color::DEFAULT, "\033[0m"    },
};

class Fetcher{
public:
    void FetchData();
    void Draw(const std::string& logo);

private:
    std::string ExecCmd(const std::string& cmd);
    std::string FindLineInFile(const std::string& path, const std::string& target = "");

    void RemoveWhitespace(std::string* str);

    std::string m_infoBuf{};
};

#endif

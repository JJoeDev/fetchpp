#ifndef FETCHPP_FETCHER_HPP
#define FETCHPP_FETCHER_HPP

#include <string>

class Fetcher{
public:
    void FetchData();
    void Draw(const std::string& logo, const std::string& logoColor);

private:
    std::string ExecCmd(const std::string& cmd);
    std::string FindLineInFile(const std::string& path, const std::string& target = "");

    void RemoveWhitespace(std::string* str);

    std::string m_infoBuf{};
};

#endif

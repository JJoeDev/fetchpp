#ifndef FETCHPP_ASSETS_HPP
#define FETCHPP_ASSETS_HPP

#include <string>
#include <unordered_map>

inline const char* fetchppVersionStr = "fetchpp - 0.0.1\n";
inline const char* HelpMessageStr = R"""(
    fetchpp - Yet another fetch app but in C++

    -h | Print the current help message
    -v | Print the current version of fetchpp

    -l | Print one of the built in logos for fetchpp (-l void)
    -- void
    -- arch
    -- nixos
    -- gentoo
    -- solus
    -- lfs
    -- debian
    -- fedora

)""";

inline std::unordered_map<std::string, const char*> packageCmd{
    { "void", "xbps-query -l | wc -l" },
};

#endif

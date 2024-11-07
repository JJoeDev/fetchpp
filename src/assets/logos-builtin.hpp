#ifndef FETCHPP_LOGOS_BUILTIN_HPP
#define FETCHPP_LOGOS_BUILTIN_HPP

#include <string>
#include <unordered_map>

inline const std::unordered_map<std::string, const char*> LogosStr = {
    { "void",
        R"""(
            _     _ 
__   _____ (_) __| |
\ \ / / _ \| |/ _` |
 \ V / (_) | | (_| |
  \_/ \___/|_|\__,_|

        )"""
    }
};

#endif

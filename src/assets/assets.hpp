#ifndef FETCHPP_ASSETS_HPP
#define FETCHPP_ASSETS_HPP

#include <string>
#include <unordered_map>

inline const char* fetchppVersionStr = "fetchpp - 0.0.1\n";
inline const char* HelpMessageStr = R"""(
    fetchpp - Yet another fetch app but in C++
    ------------------------------------------

    EXAMPLE:
    fetchpp -l void -c MAGENTA

    <no flag> | Print only the system info. No logo.

    -h | Print the current help message
    -v | Print the current version of fetchpp
    -l | Print one of the built-in logos for fetchpp.
         Use the following syntax to choose a logo:

         fetchpp -l <logo_name>
         fetchpp -l void

         Available Logos:

         -- void
         -- arch
         -- nixos
         -- gentoo
         -- solus
         -- lfs
         -- debian
         -- fedora

    -p | Use a custom logo from a file using the path flag.
         Use the following syntax to set a custom path:

         fetchpp -p <path>
         fetchpp -p ~/.config/fetchpp/MyLogo.txt

    -c | Set a color for the logo to be printed with
         Use the following syntax to set a color for the logo

         fetchpp -c <color>
         fetchpp -c GREEN

         Available Colors:

         -- BLACK
         -- RED
         -- GREEN
         -- YELLOW
         -- BLUE
         -- MAGENTA
         -- CYAN
         -- WHITE

)""";

inline std::unordered_map<std::string, const std::string> packageCmd{
    { "void", "xbps-query -l | wc -l" },
    { "arch", "pacman -Q | wc -l" },
};

#endif

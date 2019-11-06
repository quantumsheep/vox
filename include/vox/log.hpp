#pragma once

#include <iostream>
#include <string>

namespace Vox
{
static std::function<void(std::string &)> LogCallback = [](std::string &s) {
    std::cout << s << std::endl;
};

inline void SetLogCallback(std::function<void(std::string &)> cb)
{
    LogCallback = cb;
}

inline void Log(std::string str)
{
    LogCallback(str);
}
} // namespace Vox

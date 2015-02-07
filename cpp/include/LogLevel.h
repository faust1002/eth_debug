#pragma once

#include <string>

namespace application
{

enum class LogLevel
{
    DEBUG,
    LOG,
    WARN,
    ERROR,
    CRITICAL
};

LogLevel convertLogLevel(const std::string&);

} // namespace application

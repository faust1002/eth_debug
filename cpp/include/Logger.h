#pragma once

#include <iosfwd>
#include <string>
#include "ILogger.h"

namespace application
{

enum class LogLevel
{
    DEBUG = 0,
    LOG = 1,
    WARN = 2,
    ERROR = 3,
    CRITICAL = 4
};

class Logger : public ILogger
{
public:
    Logger(LogLevel, std::ostream&);
    void debug(const std::string&);
    void log(const std::string&);
    void warn(const std::string&);
    void error(const std::string&);
    void critical(const std::string&);

private:
    std::string format(const std::string&, const std::string&);
    void write(LogLevel, const std::string&);

    LogLevel m_level;
    std::ostream& m_out;
};

std::string level2string(LogLevel);

} // namespace application

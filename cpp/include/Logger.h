#pragma once

#include <iosfwd>
#include <string>

namespace application
{

enum class LogLevel
{
    DEBUG = 0,
    WARN = 1,
    ERROR = 2,
    CRITICAL = 3
};

class Logger
{
public:
    Logger(LogLevel, std::ostream&);
    void debug(const std::string&);
    void warn(const std::string&);
    void error(const std::string&);
    void critical(const std::string&);

private:
    std::string format(const std::string&);
    void write(LogLevel, const std::string&);

    LogLevel m_level;
    std::ostream& m_out;
};

} // namespace application

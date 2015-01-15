#include <iomanip>
#include <string>
#include <sstream>
#include <ctime>
#include "LogFormatter.h"

namespace application
{

std::string LogFormatter::format(LogLevel p_level, const std::string& p_msg)
{
    auto l_level = level2string(p_level);
    auto l_datetime = std::time(nullptr);
    auto l_localDateTime = std::localtime(&l_datetime);
    char l_fmtDateTime[1024];
    std::strftime(l_fmtDateTime, sizeof(l_fmtDateTime), "%Y-%m-%dT%H:%M:%S%z", l_localDateTime);

    std::ostringstream oss;
    oss.setf(std::ios::adjustfield, std::ios::left);
    oss << l_fmtDateTime << " " << std::setw(8) << l_level << " " << p_msg << "\n";
    return oss.str();
}

std::string LogFormatter::level2string(LogLevel p_level)
{
    switch(p_level)
    {
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::LOG: return "LOG";
        case LogLevel::WARN: return "WARN";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::CRITICAL: return "CRITICAL";
        default: return "UNKNOWN";
    }
}

} // namespace application

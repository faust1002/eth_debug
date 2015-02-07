#include <string>
#include "LogLevel.h"

namespace application
{

LogLevel convertLogLevel(const std::string& p_level)
{
    if ("debug" == p_level) return LogLevel::DEBUG;
    if ("log" == p_level) return LogLevel::LOG;
    if ("warn" == p_level) return LogLevel::WARN;
    if ("error" == p_level) return LogLevel::ERROR;
    if ("critical" == p_level) return LogLevel::CRITICAL;
    return LogLevel::DEBUG;
}

} // namespace application

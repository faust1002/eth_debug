#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>
#include "Logger.h"

namespace application
{

std::string level2string(LogLevel p_level)
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

Logger::Logger(LogLevel p_level, std::ostream& p_out)
    : m_level {p_level}, m_out {p_out}
{}

void Logger::debug(const std::string& p_msg)
{
    write(LogLevel::DEBUG, p_msg);
}

void Logger::log(const std::string& p_msg)
{
    write(LogLevel::LOG, p_msg);
}

void Logger::warn(const std::string& p_msg)
{
    write(LogLevel::WARN, p_msg);
}

void Logger::error(const std::string& p_msg)
{
    write(LogLevel::ERROR, p_msg);
}

void Logger::critical(const std::string& p_msg)
{
    write(LogLevel::CRITICAL, p_msg);
}

void Logger::write(LogLevel p_level, const std::string& p_msg)
{
    if (p_level >= m_level)
    {
        auto l_msg = format(level2string(p_level), p_msg);
        m_out << l_msg;
    }
}

std::string Logger::format(const std::string& p_level, const std::string& p_msg)
{
    auto l_datetime = std::time(nullptr);
    auto l_localDateTime = std::localtime(&l_datetime);
    char l_fmtDateTime[1024];
    std::strftime(l_fmtDateTime, sizeof(l_fmtDateTime), "%Y-%m-%dT%H:%M:%S%z", l_localDateTime);

    std::ostringstream oss;
    oss.setf(std::ios::adjustfield, std::ios::left);
    oss << l_fmtDateTime << " " << std::setw(8) << p_level << " " << p_msg << "\n";
    return oss.str();
}

} // namespace application

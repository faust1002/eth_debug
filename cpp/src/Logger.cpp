#include <ostream>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Logger.h"

using namespace application;

Logger::Logger(LogLevel p_level, std::ostream& p_out)
    : m_level {p_level}, m_out {p_out}
{}

void Logger::debug(const std::string& p_msg)
{
    write(LogLevel::DEBUG, p_msg);
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
        auto l_msg = format(p_msg);
        m_out << l_msg;
    }
}

std::string Logger::format(const std::string& p_msg)
{
    auto l_datetime = std::time(nullptr);
    auto l_localDateTime = std::localtime(&l_datetime);
    char l_fmtDateTime[1024];
    std::strftime(l_fmtDateTime, sizeof(l_fmtDateTime), "%Y-%m-%dT%H:%M:%S%z", l_localDateTime);

    std::ostringstream oss;
    oss << l_fmtDateTime << " " << p_msg << "\n";
    return oss.str();
}

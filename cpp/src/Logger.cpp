#include <memory>
#include <ostream>
#include <string>
#include "ILogFormatter.h"
#include "Logger.h"

namespace application
{

Logger::Logger(LogLevel p_level, std::unique_ptr<ILogFormatter> p_formatter)
    : m_level {p_level}, m_formatter {std::move(p_formatter)}
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
        auto l_msg = m_formatter->format(p_level, p_msg);
        auto& l_stream = getOutputStream();
        l_stream << l_msg;
        l_stream.flush();
    }
}

} // namespace application

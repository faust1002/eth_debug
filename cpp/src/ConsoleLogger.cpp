#include <memory>
#include <ostream>
#include <string>
#include "ILogFormatter.h"
#include "ConsoleLogger.h"

namespace application
{

ConsoleLogger::ConsoleLogger(LogLevel p_level, std::unique_ptr<ILogFormatter> p_formatter, std::ostream& p_out)
    : m_level {p_level}, m_formatter {std::move(p_formatter)}, m_out {p_out}
{}

void ConsoleLogger::debug(const std::string& p_msg)
{
    write(LogLevel::DEBUG, p_msg);
}

void ConsoleLogger::log(const std::string& p_msg)
{
    write(LogLevel::LOG, p_msg);
}

void ConsoleLogger::warn(const std::string& p_msg)
{
    write(LogLevel::WARN, p_msg);
}

void ConsoleLogger::error(const std::string& p_msg)
{
    write(LogLevel::ERROR, p_msg);
}

void ConsoleLogger::critical(const std::string& p_msg)
{
    write(LogLevel::CRITICAL, p_msg);
}

void ConsoleLogger::write(LogLevel p_level, const std::string& p_msg)
{
    if (p_level >= m_level)
    {
        auto l_msg = m_formatter->format(p_level, p_msg);
        m_out << l_msg;
    }
}

} // namespace application

#include <memory>
#include <ostream>
#include "ILogFormatter.h"
#include "ConsoleLogger.h"

namespace application
{

ConsoleLogger::ConsoleLogger(LogLevel p_level, std::unique_ptr<ILogFormatter> p_formatter, std::ostream& p_out)
    : Logger {p_level, std::move(p_formatter)}, m_out {p_out}
{}

std::ostream& ConsoleLogger::getOutputStream()
{
    return m_out;
}

} // namespace application

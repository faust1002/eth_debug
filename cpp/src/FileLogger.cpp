#include <fstream>
#include <memory>
#include <stdexcept>
#include "ILogFormatter.h"
#include "FileLogger.h"

namespace application
{

FileLogger::FileLogger(LogLevel p_level, std::unique_ptr<ILogFormatter> p_formatter, const std::string& p_filename)
    : Logger {p_level, std::move(p_formatter)}, m_out {p_filename.c_str(), std::ios::app}
{
    if (!m_out.is_open())
    {
        throw std::runtime_error("Unable to open file " + p_filename);
    }
}

std::ostream& FileLogger::getOutputStream()
{
    return m_out;
}

} // namespace application

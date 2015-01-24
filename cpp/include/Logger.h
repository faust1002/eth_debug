#pragma once

#include <iosfwd>
#include <memory>
#include <string>
#include "ILogger.h"
#include "LogLevel.h"

namespace application
{
class ILogFormatter;

class Logger : public ILogger
{
public:
    Logger(LogLevel, std::unique_ptr<ILogFormatter>, std::ostream&);
    void debug(const std::string&) override;
    void log(const std::string&) override;
    void warn(const std::string&) override;
    void error(const std::string&) override;
    void critical(const std::string&) override;

private:
    void write(LogLevel, const std::string&);

    LogLevel m_level;
    std::unique_ptr<ILogFormatter> m_formatter;
    std::ostream& m_out;
};

} // namespace application

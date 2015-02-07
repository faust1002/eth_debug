#pragma once

#include <iosfwd>
#include <memory>
#include "Logger.h"
#include "LogLevel.h"

namespace application
{
class ILogFormatter;

class ConsoleLogger : public Logger
{
public:
    ConsoleLogger(LogLevel, std::unique_ptr<ILogFormatter>, std::ostream&);

private:
    std::ostream& getOutputStream();

    std::ostream& m_out;
};

} // namespace application

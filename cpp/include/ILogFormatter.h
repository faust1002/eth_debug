#pragma once

#include <string>
#include "LogLevel.h"

namespace application
{

class ILogFormatter
{
public:
    virtual std::string format(LogLevel, const std::string&) = 0;
    virtual ~ILogFormatter() = default;
};

} // namespace application

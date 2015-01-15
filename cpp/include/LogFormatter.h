#pragma once

#include <string>
#include "ILogFormatter.h"

namespace application
{

class LogFormatter : public ILogFormatter
{
public:
    std::string format(LogLevel, const std::string&);

private:
    std::string level2string(LogLevel);
};

}

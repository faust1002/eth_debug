#pragma once

#include <string>

namespace application
{

class ILogger
{
public:
    virtual void debug(const std::string&) = 0;
    virtual void warn(const std::string&) = 0;
    virtual void error(const std::string&) = 0;
    virtual void critical(const std::string&) = 0;
    virtual ~ILogger() = default;
};

} // namespace application

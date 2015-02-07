#pragma once

#include <fstream>
#include <iosfwd>
#include <memory>
#include <string>
#include "Logger.h"
#include "LogLevel.h"

namespace application
{
class ILogFormatter;

class FileLogger : public Logger
{
public:
    FileLogger(LogLevel, std::unique_ptr<ILogFormatter>, const std::string&);

private:
    std::ostream& getOutputStream();

    std::ofstream m_out;
};

} // namespace application

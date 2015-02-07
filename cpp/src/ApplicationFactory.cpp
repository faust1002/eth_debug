#include <iostream>
#include <memory>
#include "IniFile.h"
#include "IEventHandler.h"
#include "LogEventHandler.h"
#include "VCDEventHandler.h"
#include "LogFormatter.h"
#include "ConsoleLogger.h"
#include "FileLogger.h"
#include "Application.h"
#include "ApplicationFactory.h"

namespace application
{

std::unique_ptr<Application> createApplication(const IniFile& p_iniFile)
{
    std::unique_ptr<ILogFormatter> l_formatter {new LogFormatter};
    auto l_logLevel = p_iniFile.getOption("application", "loglevel", "log");
    std::shared_ptr<ILogger> l_logger = nullptr;
    if (p_iniFile.hasOption("application", "logfile"))
    {
        l_logger = std::make_shared<FileLogger>(convertLogLevel(l_logLevel), std::move(l_formatter),
                p_iniFile.getOption("application", "logfile"));
    }
    else
    {
        l_logger = std::make_shared<ConsoleLogger>(convertLogLevel(l_logLevel), std::move(l_formatter), std::cout);
    }
    std::unique_ptr<Application> l_application{new Application(l_logger)};
    std::unique_ptr<IEventHandler> l_logHandler {new LogEventHandler(l_logger)};
    l_application->appendHandler(std::move(l_logHandler));
    std::unique_ptr<IEventHandler> l_vcdHandler {new VCDEventHandler};
    l_application->appendHandler(std::move(l_vcdHandler));
    return l_application;
}

} // namespace application

#include <iostream>
#include <memory>
#include <IEventHandler.h>
#include "LogEventHandler.h"
#include "VCDEventHandler.h"
#include "LogFormatter.h"
#include "ConsoleLogger.h"
#include "Application.h"
#include "ApplicationFactory.h"

namespace application
{

std::unique_ptr<Application> createApplication()
{
    std::unique_ptr<ILogFormatter> l_formatter {new LogFormatter};
    auto l_logger = std::make_shared<ConsoleLogger>(LogLevel::DEBUG, std::move(l_formatter), std::cout);
    std::unique_ptr<Application> l_application{new Application(l_logger)};
    std::unique_ptr<IEventHandler> l_logHandler {new LogEventHandler(l_logger)};
    l_application->appendHandler(std::move(l_logHandler));
    std::unique_ptr<IEventHandler> l_vcdHandler {new VCDEventHandler};
    l_application->appendHandler(std::move(l_vcdHandler));
    return l_application;
}

} // namespace application

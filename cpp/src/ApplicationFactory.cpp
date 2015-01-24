#include <iostream>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <IEventHandler.h>
#include "LogEventHandler.h"
#include "VCDEventHandler.h"
#include "LogFormatter.h"
#include "Logger.h"
#include "Application.h"
#include "ApplicationFactory.h"

namespace application
{

std::shared_ptr<Application> createApplication()
{
    std::unique_ptr<std::mutex> l_mutex {new std::mutex};
    std::unique_ptr<std::condition_variable> l_variable {new std::condition_variable};
    std::unique_ptr<ILogFormatter> l_formatter {new LogFormatter};
    auto l_logger = std::make_shared<Logger>(LogLevel::DEBUG, std::move(l_formatter), std::cout);
    auto l_application = std::make_shared<Application>(l_logger, std::move(l_mutex), std::move(l_variable));
    std::unique_ptr<IEventHandler> l_logHandler {new LogEventHandler(l_logger)};
    l_application->appendHandler(std::move(l_logHandler));
    std::unique_ptr<IEventHandler> l_vcdHandler {new VCDEventHandler};
    l_application->appendHandler(std::move(l_vcdHandler));
    return l_application;
}

} // namespace application

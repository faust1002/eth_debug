#include <iostream>
#include <memory>
#include <mutex>
#include <condition_variable>
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
    std::unique_ptr<ILogger> l_logger {new Logger {LogLevel::DEBUG, std::move(l_formatter), std::cout}};
    return std::make_shared<Application>(std::move(l_logger), std::move(l_mutex), std::move(l_variable));
}

} // namespace application

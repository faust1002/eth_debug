#include <iostream>
#include <memory>
#include <mutex>
#include <condition_variable>
#include "Logger.h"
#include "Application.h"
#include "ApplicationFactory.h"

using namespace application;

std::shared_ptr<application::Application> application::createApplication()
{
    std::unique_ptr<std::mutex> l_mutex {new std::mutex};
    std::unique_ptr<std::condition_variable> l_variable {new std::condition_variable};
    std::unique_ptr<application::ILogger> l_logger {new application::Logger {application::LogLevel::DEBUG, std::cout}};
    return std::make_shared<application::Application>(std::move(l_logger), std::move(l_mutex), std::move(l_variable));
}

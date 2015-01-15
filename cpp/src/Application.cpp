#include <memory>
#include <mutex>
#include <condition_variable>
#include "Logger.h"
#include "Application.h"

using namespace application;

Application::Application(std::unique_ptr<ILogger> p_logger, std::unique_ptr<std::mutex> p_mutex,
                         std::unique_ptr<std::condition_variable> p_variable)
    : m_logger {std::move(p_logger)}, m_mutex {std::move(p_mutex)}, m_variable {std::move(p_variable)}
{}

void Application::run()
{
    std::unique_lock<std::mutex> l_lock {*m_mutex};
    bool l_run = true;
    m_logger->log("Starting debugger");
    while (l_run)
    {
        m_variable->wait(l_lock);
        l_run = false;
    }
    m_logger->log("Debugger finished");
}

void Application::notify()
{
    m_logger->debug("Received notification");
    std::unique_lock<std::mutex> l_lock {*m_mutex};
    m_variable->notify_one();
}

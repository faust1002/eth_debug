#include <algorithm>
#include <memory>
#include <mutex>
#include <condition_variable>
#include "ILogger.h"
#include "Event.h"
#include "Payload.h"
#include "Application.h"

using namespace application;

Application::Application(std::shared_ptr<ILogger> p_logger)
    : m_logger {p_logger}
{}

void Application::run()
{
    std::unique_lock<std::mutex> l_lock {m_mutex};
    bool l_run = true;
    m_logger->log("Starting debugger");
    while (l_run)
    {
        m_variable.wait(l_lock);
        l_run = false;
    }
    m_logger->log("Debugger finished");
}

void Application::notify(std::shared_ptr<Event> p_event)
{
    for (auto& l_eventHandler : m_eventHandlers)
    {
        l_eventHandler->handleEvent(p_event);
    }
    if (p_event->isStopEvent())
    {
        std::unique_lock<std::mutex> l_lock {m_mutex};
        m_variable.notify_one();
    }
}

void Application::appendHandler(std::unique_ptr<IEventHandler> p_eventHandler)
{
    m_eventHandlers.push_back(std::move(p_eventHandler));
}

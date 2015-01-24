#pragma once

#include <condition_variable>
#include <memory>
#include <mutex>
#include <vector>
#include "IObserver.h"
#include "IEventHandler.h"

namespace application
{
class Event;
class ILogger;

class Application : public IObserver
{
public:
    Application(std::shared_ptr<ILogger>, std::unique_ptr<std::mutex>, std::unique_ptr<std::condition_variable>);
    void run();
    void notify(std::shared_ptr<Event>) override;
    void appendHandler(std::unique_ptr<IEventHandler>);

private:
    std::shared_ptr<ILogger> m_logger;
    std::unique_ptr<std::mutex> m_mutex;
    std::unique_ptr<std::condition_variable> m_variable;
    std::vector<std::unique_ptr<IEventHandler>> m_eventHandlers;
};

} // namespace application

#pragma once

#include <memory>
#include <mutex>
#include <condition_variable>
#include "IObserver.h"

namespace application
{
class ILogger;

class Application : public IObserver
{
public:
    Application(std::unique_ptr<ILogger>, std::unique_ptr<std::mutex>, std::unique_ptr<std::condition_variable>);
    void run();
    void notify();

private:
    std::unique_ptr<ILogger> m_logger;
    std::unique_ptr<std::mutex> m_mutex;
    std::unique_ptr<std::condition_variable> m_variable;
};

} // namespace application

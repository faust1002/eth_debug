#pragma once

#include <memory>
#include "IEventHandler.h"

namespace application
{
class Event;
class ILogger;

class LogEventHandler : public IEventHandler
{
public:
    LogEventHandler(std::shared_ptr<ILogger>);
    void handleEvent(std::shared_ptr<Event>) override;

private:
    std::shared_ptr<ILogger> m_logger;
};

} // namespace application

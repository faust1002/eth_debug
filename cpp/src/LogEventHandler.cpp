#include "Event.h"
#include "ILogger.h"
#include "LogEventHandler.h"

namespace application
{

LogEventHandler::LogEventHandler(std::shared_ptr<ILogger> p_logger) : m_logger {p_logger}
{}

void LogEventHandler::handleEvent(std::shared_ptr<Event> p_event)
{
    if (p_event->isStartEvent())
    {
        m_logger->log("Received start event");
    }
    else if (p_event->isStopEvent())
    {
        m_logger->log("Received stop event");
    }
    else
    {
        m_logger->debug("Received event");
        m_logger->debug(p_event->getPayload().toString());
    }
}

} // namespace application

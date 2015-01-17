#include "StopEvent.h"

namespace application
{

EventType StopEvent::getEventType() const
{
    return EventType::STOP;
}

} // namespace application

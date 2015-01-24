#include "StopEvent.h"

namespace application
{

StopEvent::StopEvent(const Payload& p_payload) : Event {p_payload}
{}

EventType StopEvent::getEventType() const
{
    return EventType::STOP;
}

} // namespace application

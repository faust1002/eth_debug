#include "BasicEvent.h"
#include "Payload.h"

namespace application
{

BasicEvent::BasicEvent(const Payload& p_payload) : Event {p_payload}
{}

EventType BasicEvent::getEventType() const
{
    return EventType::BASIC;
}

} // namespace application

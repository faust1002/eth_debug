#include "StartEvent.h"
#include "Payload.h"

namespace application
{

StartEvent::StartEvent(const Payload& p_payload) : Event {p_payload}
{}

EventType StartEvent::getEventType() const
{
    return EventType::START;
}

} // namespace application

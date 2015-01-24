#include "UndefinedEvent.h"

namespace application
{

UndefinedEvent::UndefinedEvent() : Event {0xFF}
{}

EventType UndefinedEvent::getEventType() const
{
    return EventType::UNDEFINED;
}

};

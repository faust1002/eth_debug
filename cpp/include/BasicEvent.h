#pragma once

#include "Event.h"
#include "Payload.h"

namespace application
{

class BasicEvent : public Event
{
public:
    BasicEvent(const Payload&);
    EventType getEventType() const;
};

} // namespace application

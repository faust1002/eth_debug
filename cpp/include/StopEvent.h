#pragma once

#include "Event.h"
#include "Payload.h"

namespace application
{

class StopEvent : public Event
{
public:
    StopEvent(const Payload&);
    EventType getEventType() const;
};

} // namespace application

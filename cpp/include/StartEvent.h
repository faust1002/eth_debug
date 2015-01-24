#pragma once

#include "Event.h"
#include "Payload.h"

namespace application
{

class StartEvent : public Event
{
public:
    StartEvent(const Payload&);
    EventType getEventType() const;
};

} // namespace application

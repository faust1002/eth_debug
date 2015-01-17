#pragma once

#include "Event.h"

namespace application
{

class StopEvent : public Event
{
public:
    EventType getEventType() const;
};

} // namespace application

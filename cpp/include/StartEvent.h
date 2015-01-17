#pragma once

#include "Event.h"

namespace application
{

class StartEvent : public Event
{
public:
    EventType getEventType() const;
};

} // namespace application

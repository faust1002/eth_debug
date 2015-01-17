#pragma once

#include "Event.h"

namespace application
{

class BasicEvent : public Event
{
public:
    EventType getEventType() const;
};

} // namespace application

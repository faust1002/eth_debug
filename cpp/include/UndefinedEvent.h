#pragma once

#include "Event.h"

namespace application
{

class UndefinedEvent : public Event
{
public:
    EventType getEventType() const;
};

} // namespace application
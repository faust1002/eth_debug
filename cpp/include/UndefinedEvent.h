#pragma once

#include "Event.h"

namespace application
{

class UndefinedEvent : public Event
{
public:
    UndefinedEvent();
    EventType getEventType() const;
};

} // namespace application

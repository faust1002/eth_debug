#pragma once

#include "Event.h"

namespace application
{

class UndefinedEvent : public Event
{
    EventType getEventType() const;
};

} // namespace application

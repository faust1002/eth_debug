#pragma once

#include <cstdint>

namespace application
{
class Payload;

enum class EventType
{
    UNDEFINED = 0,
    START = 1,
    BASIC = 2,
    STOP = 3
};

class IEvent
{
public:
    virtual Payload getPayload() const = 0;
    virtual EventType getEventType() const = 0;
    virtual ~IEvent() = default;
};

} // namespace application

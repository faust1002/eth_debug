#pragma once

#include "Payload.h"

namespace application
{

class Event
{
public:
    Event(const Payload&);
    bool isStartEvent() const;
    bool isStopEvent() const;
    Payload getPayload() const;

private:
    Payload m_payload;

    const uint16_t m_startDelimiter {0x5354};
    const uint16_t m_stopDelimiter {0x5350};
};

} // namespace application

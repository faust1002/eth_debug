#pragma once

#include "IEvent.h"
#include "Payload.h"

namespace application
{

class Event : public IEvent
{
public:
    Event(const Payload&);
    Payload getPayload() const;

private:
    Payload m_payload;
};

} // namespace application

#include "Event.h"
#include "Payload.h"

namespace application
{

Event::Event(const Payload& p_payload) : m_payload {p_payload}
{}

Payload Event::getPayload() const
{
    return m_payload;
}

} // namespace application

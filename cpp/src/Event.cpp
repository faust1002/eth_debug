#include <cstdint>
#include "Event.h"
#include "Payload.h"

namespace application
{

Payload Event::getPayload() const
{
    return Payload {0u};
}

} // namespace application

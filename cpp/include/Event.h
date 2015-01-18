#pragma once

#include <cstdint>
#include "IEvent.h"

namespace application
{
class Payload;

class Event : public IEvent
{
public:
    Payload getPayload() const;
};

} // namespace application

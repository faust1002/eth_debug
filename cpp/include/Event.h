#pragma once

#include <cstdint>
#include "IEvent.h"

namespace application
{

class Event //: public IEvent
{
public:
    uint8_t getPayload() const;
};

} // namespace application

#pragma once

#include <memory>

namespace application
{
class Event;

class IEventHandler
{
public:
    virtual void handleEvent(std::shared_ptr<Event>) = 0;
    ~IEventHandler() = default;
};

} // namespace application

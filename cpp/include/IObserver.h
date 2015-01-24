#pragma once

#include <memory>

namespace application
{
class Event;

class IObserver
{
public:
    virtual void notify(std::unique_ptr<Event>) = 0;
    virtual ~IObserver() = default;
};

} // namespace application

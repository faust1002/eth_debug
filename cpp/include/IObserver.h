#pragma once

#include <memory>

namespace application
{
class IEvent;

class IObserver
{
public:
    virtual void notify(std::unique_ptr<IEvent>) = 0;
    virtual ~IObserver() = default;
};

} // namespace application

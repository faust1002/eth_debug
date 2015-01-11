#pragma once

namespace application
{

class IObserver
{
public:
    virtual void notify() = 0;
    virtual ~IObserver() = default;
};

} // namespace application

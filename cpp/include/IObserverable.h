#pragma once

namespace application
{
class IObserver;

class IObserverable
{
public:
    virtual void addObserver(IObserver*) = 0;
    virtual void notifyObservers() = 0;
    virtual ~IObserverable() = default;
};

} // namespace application

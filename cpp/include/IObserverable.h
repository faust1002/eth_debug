#pragma once

#include <memory>

namespace application
{
class IObserver;

class IObserverable
{
public:
    virtual void addObserver(std::weak_ptr<IObserver>) = 0;
    virtual void notifyObservers() = 0;
    virtual ~IObserverable() = default;
};

} // namespace application

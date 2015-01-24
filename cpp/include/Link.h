#pragma once

#include <memory>
#include <vector>
#include "IObserverable.h"

namespace application
{
class IObserver;
class IEvent;
} // namespace application

namespace debugger
{

class Link : public application::IObserverable
{
public:
    void run();
    void addObserver(std::weak_ptr<application::IObserver>);
    void notifyObservers(std::shared_ptr<application::Event>);

private:
    std::vector<std::weak_ptr<application::IObserver>> m_observers;
};

} // namespace debugger

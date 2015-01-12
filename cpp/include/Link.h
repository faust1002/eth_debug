#pragma once

#include <memory>
#include <vector>
#include "IObserver.h"
#include "IObserverable.h"

namespace debugger
{

class Link : public application::IObserverable
{
public:
    void run();
    void addObserver(std::weak_ptr<application::IObserver>);
    void notifyObservers();

private:
    std::vector<std::weak_ptr<application::IObserver>> m_observers;
};

} // namespace debugger

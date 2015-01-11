#pragma once

#include <vector>
#include "IObserver.h"
#include "IObserverable.h"

namespace debugger
{

class Link : public application::IObserverable
{
public:
    void operator()();
    void addObserver(application::IObserver*);
    void notifyObservers();

private:
    std::vector<application::IObserver*> m_observers;
};

} // namespace debugger

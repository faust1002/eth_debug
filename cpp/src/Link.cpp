#include <memory>
#include "IObserver.h"
#include "Link.h"

using namespace debugger;

void Link::run()
{
    notifyObservers();
}

void Link::addObserver(std::weak_ptr<application::IObserver> p_observer)
{
    m_observers.push_back(p_observer);
}

void Link::notifyObservers()
{
    for (auto& l_observer : m_observers)
    {
        if (auto l_ob = l_observer.lock())
        {
            l_ob->notify();
        }
    }
}

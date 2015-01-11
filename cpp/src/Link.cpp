#include "IObserver.h"
#include "Link.h"

using namespace debugger;

void Link::operator()()
{
    notifyObservers();
}

void Link::addObserver(application::IObserver* p_observer)
{
    m_observers.push_back(p_observer);
}

void Link::notifyObservers()
{
    for (auto& l_oberver : m_observers)
    {
        l_oberver->notify();
    }
}

#include <chrono>
#include <memory>
#include <thread>
#include "Event.h"
#include "IObserver.h"
#include "LinkRS232.h"
#include "Event.h"
#include "Link.h"

using namespace debugger;

void Link::run()
{
    LinkRS232 l_linkRS232 {"/dev/ftdi", LinkSpeed::SPEED115200};
    std::chrono::milliseconds l_duration {100};
    bool l_run = true;
    while (l_run)
    {
        if (l_linkRS232.hasData())
        {
            auto l_data = l_linkRS232.readData();
            std::unique_ptr<application::Event> l_event {new application::Event(l_data)};
            l_run = !l_event->isStopEvent();
            notifyObservers(std::move(l_event));
        }
        else
        {
            std::this_thread::sleep_for(l_duration);
        }
    }
}

void Link::addObserver(std::weak_ptr<application::IObserver> p_observer)
{
    m_observers.push_back(p_observer);
}

void Link::notifyObservers(std::unique_ptr<application::Event> p_event)
{
    for (auto& l_observer : m_observers)
    {
        if (auto l_ob = l_observer.lock())
        {
            l_ob->notify(std::move(p_event));
        }
    }
}

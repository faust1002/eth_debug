#include <algorithm>
#include <chrono>
#include <memory>
#include <thread>
#include "Event.h"
#include "IObserver.h"
#include "LinkRS232.h"
#include "Event.h"
#include "Link.h"

using namespace debugger;

Link::Link(const std::string& p_path) : m_linkHw {new LinkRS232 {p_path, LinkSpeed::SPEED115200}}
{}

void Link::run()
{
    std::chrono::milliseconds l_duration {100};
    bool l_run = true;
    while (l_run)
    {
        if (m_linkHw->hasData())
        {
            auto l_data = m_linkHw->readData();
            auto l_event = std::make_shared<application::Event>(l_data);
            l_run = !l_event->isStopEvent();
            notifyObservers(l_event);
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

void Link::notifyObservers(std::shared_ptr<application::Event> p_event)
{
    std::for_each(m_observers.begin(), m_observers.end(),
    [&](std::weak_ptr<application::IObserver> p_observer)
    {
        if (auto l_ob = p_observer.lock())
        {
            l_ob->notify(p_event);
        }
    });
}

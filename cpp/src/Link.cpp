#include <chrono>
#include <memory>
#include <thread>
#include "IEvent.h"
#include "IObserver.h"
#include "LinkRS232.h"
#include "BasicEvent.h"
#include "StartEvent.h"
#include "StopEvent.h"
#include "Link.h"

namespace
{

std::unique_ptr<application::IEvent> prepareEvent(uint16_t p_data)
{
    if (0x5053 == p_data)
    {
        return std::unique_ptr<application::IEvent> {new application::StopEvent};
    }
    else if (0x5354 == p_data)
    {
        return std::unique_ptr<application::IEvent> {new application::StartEvent};
    }
    else
    {
        return std::unique_ptr<application::IEvent> {new application::BasicEvent};
    }
}

} // namespace anonymous

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
            auto l_event = prepareEvent(l_data);
            if (application::EventType::STOP == l_event->getEventType())
            {
                l_run = false;
            }
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

void Link::notifyObservers(std::unique_ptr<application::IEvent> p_event)
{
    for (auto& l_observer : m_observers)
    {
        if (auto l_ob = l_observer.lock())
        {
            l_ob->notify(std::move(p_event));
        }
    }
}

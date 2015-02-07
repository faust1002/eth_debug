#pragma once

#include <memory>
#include <vector>
#include "IObserverable.h"
#include "LinkRS232.h"

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
    Link();
    void run();
    void addObserver(std::weak_ptr<application::IObserver>) override;
    void notifyObservers(std::shared_ptr<application::Event>);

private:
    std::vector<std::weak_ptr<application::IObserver>> m_observers;
    std::unique_ptr<ILinkHw> m_linkHw;
};

} // namespace debugger

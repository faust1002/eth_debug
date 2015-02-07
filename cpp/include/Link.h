#pragma once

#include <memory>
#include <string>
#include <vector>
#include "IObserverable.h"
#include "LinkRS232.h"

namespace application
{
class IObserver;
class Event;
} // namespace application

namespace debugger
{

class Link : public application::IObserverable
{
public:
    Link(const std::string&);
    void run();
    void addObserver(std::weak_ptr<application::IObserver>) override;

private:
    void notifyObservers(std::shared_ptr<application::Event>);

    std::vector<std::weak_ptr<application::IObserver>> m_observers;
    std::unique_ptr<ILinkHw> m_linkHw;
};

} // namespace debugger

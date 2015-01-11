#pragma once

#include "IObserver.h"

namespace application
{
class ILogger;

class Application
{
public:
    Application(ILogger&);
    void operator()();
    void notify();

private:
    ILogger& m_logger;
};

} // namespace application

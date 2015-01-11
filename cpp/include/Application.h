#pragma once

#include "IObserver.h"

namespace application
{
class ILogger;

class Application : public IObserver
{
public:
    Application(ILogger&);
    void operator()();
    void notify();

private:
    ILogger& m_logger;
    //bool m_run;
};

} // namespace application

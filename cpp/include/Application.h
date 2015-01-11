#pragma once

namespace application
{
class ILogger;

class Application
{
public:
    Application(ILogger&);
    void operator()();

private:
    ILogger& m_logger;
};

} // namespace application

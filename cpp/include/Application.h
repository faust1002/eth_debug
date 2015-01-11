#pragma once

namespace application
{
class Logger;

class Application
{
public:
    Application(Logger&);
    void operator()();

private:
    Logger& m_logger;
};

} // namespace application

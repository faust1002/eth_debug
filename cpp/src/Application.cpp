#include "Logger.h"
#include "Application.h"

using namespace application;

Application::Application(ILogger& l_logger) : m_logger {l_logger}//, m_run {true}
{}

void Application::operator()()
{
    m_logger.debug("Starting debugger");
    //while (m_run.load());
    m_logger.debug("Debugger finished");
}

void Application::notify()
{
    m_logger.debug("Received notification");
    //m_run = false;
}

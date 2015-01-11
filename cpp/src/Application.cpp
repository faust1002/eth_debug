#include "Logger.h"
#include "Application.h"

using namespace application;

Application::Application(ILogger& l_logger) : m_logger {l_logger}
{}

void Application::operator()()
{
    m_logger.debug("Starting debugger");
    m_logger.debug("Debugger finished");
}

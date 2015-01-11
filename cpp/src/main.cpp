#include <iostream>
#include <thread>
#include "Logger.h"
#include "Application.h"
#include "Link.h"
using namespace std;

int main()
{
    application::Logger l_logger {application::LogLevel::DEBUG, std::cout};
    application::Application l_app {l_logger};
    debugger::Link l_link;
    l_link.addObserver(&l_app);
    std::thread l_appThread {l_app};
    std::thread l_linkThread {l_link};
    l_appThread.join();
    l_linkThread.join();
    return 0;
}

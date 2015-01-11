#include <iostream>
#include <thread>
#include "Application.h"
#include "Logger.h"
using namespace std;

int main()
{
    application::Logger l_logger {application::LogLevel::DEBUG, std::cout};
    application::Application l_app {l_logger};
    std::thread l_appThread {l_app};
    l_appThread.join();
    return 0;
}

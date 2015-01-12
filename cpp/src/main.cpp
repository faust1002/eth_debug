#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "Logger.h"
#include "Application.h"
#include "Link.h"
using namespace std;

int main()
{
    //TODO make factory for application
    std::unique_ptr<std::mutex> l_mutex {new std::mutex};
    std::unique_ptr<std::condition_variable> l_variable {new std::condition_variable};
    std::unique_ptr<application::ILogger> l_logger {new application::Logger {application::LogLevel::DEBUG, std::cout}};
    std::shared_ptr<application::Application> l_app = std::make_shared<application::Application>(std::move(l_logger), std::move(l_mutex), std::move(l_variable));
    std::shared_ptr<debugger::Link> l_link = std::make_shared<debugger::Link>();
    l_link->addObserver(l_app);
    std::thread l_appThread {[&]{l_app->run();}};
    std::thread l_linkThread {[&]{l_link->run();}};
    l_appThread.join();
    l_linkThread.join();
    return 0;
}

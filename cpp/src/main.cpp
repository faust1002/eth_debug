#include <exception>
#include <iostream>
#include <memory>
#include <thread>
#include "Application.h"
#include "ApplicationFactory.h"
#include "Link.h"
using namespace std;

int main()
{
    try
    {
        auto l_app = application::createApplication();
        auto l_link = std::make_shared<debugger::Link>();
        l_link->addObserver(l_app);
        std::thread l_appThread {[&]{l_app->run();}};
        std::thread l_linkThread {[&]{l_link->run();}};
        l_appThread.join();
        l_linkThread.join();
        return 0;
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
        return 100;
    }
}

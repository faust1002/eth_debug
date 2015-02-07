#include <exception>
#include <iostream>
#include <memory>
#include <thread>
#include "IniFile.h"
#include "Application.h"
#include "ApplicationFactory.h"
#include "Link.h"
using namespace std;

int main(int argc, char** argv)
{
    if (2 != argc)
    {
        std::cerr << "usage: debugger <config.ini>" << std::endl;
        return 100;
    }
    try
    {
        application::IniFile l_iniFile {argv[1]};
        std::shared_ptr<application::Application> l_app = application::createApplication(l_iniFile);
        std::unique_ptr<debugger::Link> l_link {new debugger::Link};
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
        return 200;
    }
}

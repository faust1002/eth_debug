#include <memory>
#include <string>
#include "IniFile.h"
#include "Link.h"
#include "ApplicationFactory.h"

namespace debugger
{

std::unique_ptr<Link> createLink(const application::IniFile& p_iniFile)
{
    std::string l_device = "/dev/ftdi";
    if (p_iniFile.hasOption("debugger", "device"))
    {
        l_device = p_iniFile.getOption("debugger", "device");
    }
    std::unique_ptr<debugger::Link> l_link {new debugger::Link{l_device}};
    return l_link;
}

} // namespace debugger

#include <memory>
#include <string>
#include "IniFile.h"
#include "LinkSpeedConverter.h"
#include "Link.h"
#include "LinkFactory.h"

namespace debugger
{

std::unique_ptr<Link> createLink(const application::IniFile& p_iniFile)
{
    auto l_device = p_iniFile.getOption("debugger", "device", "/dev/ftdi");
    auto l_speed = p_iniFile.getOption("debugger", "speed", "115200");
    std::unique_ptr<debugger::Link> l_link {new debugger::Link{l_device, convertSpeed(l_speed)}};
    return l_link;
}

} // namespace debugger

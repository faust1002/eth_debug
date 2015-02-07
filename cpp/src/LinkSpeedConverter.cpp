#include <termios.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "ILinkHw.h"
#include "LinkSpeedConverter.h"

namespace debugger
{

ILinkHw::ILinkSpeed convertSpeed(const std::string& p_speed)
{
    if ("9600" == p_speed) return B9600;
    else if ("19200" == p_speed) return B19200;
    else if ("115200" == p_speed) return B115200;
    else throw std::runtime_error("Unknown link speed");
    return B0;
}

} // namespace debugger

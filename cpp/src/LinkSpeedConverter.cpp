#include <stdexcept>
#include "LinkSpeed.h"
#include "LinkSpeedConverter.h"

namespace debugger
{

speed_t convertSpeed(LinkSpeed p_linkSpeed)
{
    switch (p_linkSpeed)
    {
        case(LinkSpeed::SPEED9600): return B9600;
        case(LinkSpeed::SPEED19200): return B19200;
        case(LinkSpeed::SPEED115200): return B115200;
        default: throw std::runtime_error("Unknown link speed");
    }
    return B0;
}

} // namespace debugger

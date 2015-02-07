#pragma once

#include <cstdint>
#include <termios.h>

namespace debugger
{

class ILinkHw
{
public:
    using ILinkSpeed = speed_t;
    virtual bool hasData() = 0;
    virtual uint16_t readData() = 0;
    ~ILinkHw() = default;
};

} // namespace debugger

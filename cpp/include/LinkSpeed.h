#pragma once

#include <termios.h>

namespace debugger
{

enum class LinkSpeed
{
    SPEED9600 = 0,
    SPEED19200 = 1,
    SPEED115200 = 2
};

} // namespace debugger

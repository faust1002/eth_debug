#pragma once

#include <cstdint>

namespace debugger
{

class ILinkHw
{
public:
    virtual bool hasData() = 0;
    virtual uint16_t readData() = 0;
    ~ILinkHw() = default;
};

} // namespace debugger

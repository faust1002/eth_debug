#pragma once

#include <cstdint>
#include "ILinkHw.h"

namespace debugger
{

class LinkRS232 : public ILinkHw
{
public:
    bool hasData();
    uint16_t readData();
};

} // namespace debugger;

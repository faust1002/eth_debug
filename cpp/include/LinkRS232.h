#pragma once

#include <string>
#include <cstdint>
#include "ILinkHw.h"

namespace debugger
{

class LinkRS232 : public ILinkHw
{
public:
    LinkRS232(const std::string&);
    LinkRS232(const LinkRS232&) = delete;
    LinkRS232(LinkRS232&&) = delete;
    LinkRS232& operator=(const LinkRS232&) = delete;
    LinkRS232& operator=(LinkRS232&&) = delete;
    bool hasData();
    uint16_t readData();
};

} // namespace debugger;

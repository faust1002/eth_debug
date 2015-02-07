#pragma once

#include <string>
#include "ILinkHw.h"

namespace debugger
{

ILinkHw::ILinkSpeed convertSpeed(const std::string&);

} // namespace debugger

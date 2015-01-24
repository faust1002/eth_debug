#include <cstdint>
#include "LinkRS232.h"

namespace debugger
{

LinkRS232::LinkRS232(const std::string&)
{}

bool LinkRS232::hasData()
{
    return false;
}

uint16_t LinkRS232::readData()
{
    return 0u;
}

} // namespace debugger

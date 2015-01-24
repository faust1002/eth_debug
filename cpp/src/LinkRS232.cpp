#include <cstdint>
#include "LinkRS232.h"

namespace debugger
{

bool LinkRS232::hasData()
{
    return false;
}

uint16_t LinkRS232::readData()
{
    return 0u;
}

} // namespace debugger

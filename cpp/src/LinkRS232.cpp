#include <cstdint>
#include "LinkRS232.h"

namespace debugger
{

LinkRS232::LinkRS232(const std::string& p_path)
{
    openConnection(p_path);
}

bool LinkRS232::hasData()
{
    return false;
}

uint16_t LinkRS232::readData()
{
    return 0u;
}

LinkRS232::~LinkRS232()
{
    closeConnection();
}

void LinkRS232::openConnection(const std::string&)
{}

void LinkRS232::closeConnection()
{}

} // namespace debugger

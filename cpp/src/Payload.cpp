#include <iomanip>
#include <ostream>
#include <sstream>
#include <string>
#include <cstdint>
#include "Payload.h"

namespace application
{

Payload::Payload(uint16_t p_payload) : m_payload {p_payload}
{}

uint16_t Payload::getPayload() const
{
    return m_payload;
}

std::string Payload::toString() const
{
    std::ostringstream oss;
    oss << "Payload 0x" << std::hex << m_payload;
    return oss.str();
}

std::ostream& operator<<(std::ostream& os, const Payload& p_rhs)
{
    os << p_rhs.toString();
    return os;
}

}

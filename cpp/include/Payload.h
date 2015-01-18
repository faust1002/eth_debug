#pragma once

#include <iosfwd>
#include <string>
#include <cstdint>

namespace application
{

class Payload
{
public:
    Payload(uint16_t);
    uint16_t getPayload() const;
    std::string toString() const;

private:
    uint16_t m_payload;
};

std::ostream& operator<<(std::ostream&, const Payload&);

} // namespace application

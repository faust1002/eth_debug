#pragma once

#include <string>
#include <cstdint>
#include "ILinkHw.h"
#include "LinkSpeed.h"

namespace debugger
{

class LinkRS232 : public ILinkHw
{
public:
    LinkRS232(const std::string&, LinkSpeed);
    LinkRS232(const LinkRS232&) = delete;
    LinkRS232(LinkRS232&&) = delete;
    LinkRS232& operator=(const LinkRS232&) = delete;
    LinkRS232& operator=(LinkRS232&&) = delete;
    bool hasData();
    uint16_t readData();
    ~LinkRS232();

private:
    void openConnection(const std::string&, LinkSpeed);
    void closeConnection();

    int m_fd;
    uint16_t m_data;
};

} // namespace debugger;

#include <cstdint>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <stdexcept>
#include "ILinkHw.h"
#include "LinkRS232.h"

//UGLY C-STYLE CODE
namespace debugger
{

LinkRS232::LinkRS232(const std::string& p_path, ILinkHw::ILinkSpeed p_linkSpeed)
{
    openConnection(p_path, p_linkSpeed);
}

bool LinkRS232::hasData()
{
    const size_t l_length = 2;
    uint8_t l_data[l_length];
    ssize_t l_read = read(m_fd, l_data, l_length);
    m_data = (static_cast<uint16_t>(l_data[0]) << 8) | (l_data[1]);
    return l_read == l_length;
}

uint16_t LinkRS232::readData()
{
    return m_data;
}

LinkRS232::~LinkRS232()
{
    closeConnection();
}

void LinkRS232::openConnection(const std::string& p_path, ILinkHw::ILinkSpeed p_linkSpeed)
{
    m_fd = open(p_path.c_str(), O_RDONLY, O_NONBLOCK);
    if (-1 == m_fd)
    {
        throw std::runtime_error("Unable to open device " + p_path);
    }
    termios l_rs232;
    l_rs232.c_lflag = 0;
    l_rs232.c_oflag = 0;
    l_rs232.c_cflag = CS8 | CREAD | CLOCAL;
    l_rs232.c_cc[VMIN] = 1;
    l_rs232.c_cc[VTIME] = 5;
    cfsetospeed(&l_rs232, p_linkSpeed);
    cfsetispeed(&l_rs232, p_linkSpeed);
    tcsetattr(m_fd, TCSANOW, &l_rs232);
}

void LinkRS232::closeConnection()
{
    close(m_fd);
}

} // namespace debugger

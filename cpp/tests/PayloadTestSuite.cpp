#include "gtest/gtest.h"
#include "Payload.h"

using namespace testing;

namespace ut
{

class PayloadTestSuite : public Test
{

public:
    const uint16_t m_payload {0xFFFF};
    application::Payload m_sut {m_payload};
};

TEST_F(PayloadTestSuite, testGetPayload)
{
    ASSERT_EQ(m_payload, m_sut.getPayload());
}

} // namespace ut

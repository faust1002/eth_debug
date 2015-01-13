#include <memory>
#include "gtest/gtest.h"
#include "ObserverMock.hpp"
#include "Link.h"

using namespace testing;

namespace ut
{

class LinkTestSuite : public Test
{
public:
	debugger::Link m_link;
};

TEST_F(LinkTestSuite, willNotifyObserver)
{
	auto l_observer = std::make_shared<StrictMock<ObserverMock>>();
	EXPECT_CALL(*l_observer, notify());
	m_link.addObserver(l_observer);
	m_link.notifyObservers();
}

} // namespace ut

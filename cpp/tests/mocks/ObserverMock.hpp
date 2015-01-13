#pragma once

#include "gmock/gmock.h"
#include "IObserver.h"

namespace ut
{

class ObserverMock : public application::IObserver
{
public:
	MOCK_METHOD0(notify, void());
};

} // namespace ut

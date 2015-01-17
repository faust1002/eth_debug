#pragma once

#include <memory>
#include "gmock/gmock.h"
#include "IEvent.h"
#include "IObserver.h"

namespace ut
{

class ObserverMock : public application::IObserver
{
public:
	MOCK_METHOD1(notify, void(std::shared_ptr<application::IEvent>));
};

} // namespace ut

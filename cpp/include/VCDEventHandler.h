#pragma once

#include <memory>
#include "IEventHandler.h"

namespace application
{

class VCDEventHandler : public IEventHandler
{
public:
    void handleEvent(std::shared_ptr<Event>) override;
};

} // namespace application

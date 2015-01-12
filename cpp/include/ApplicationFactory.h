#pragma once

#include <memory>

namespace application
{
class Application;

std::shared_ptr<Application> createApplication();

}

#pragma once

#include <memory>

namespace application
{
class Application;

std::unique_ptr<Application> createApplication();

}

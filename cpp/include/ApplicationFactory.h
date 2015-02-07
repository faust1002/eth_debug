#pragma once

#include <memory>

namespace application
{
class Application;
class IniFile;

std::unique_ptr<Application> createApplication(const IniFile&);

}

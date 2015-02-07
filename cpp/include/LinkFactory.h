#pragma once

#include <memory>

namespace debugger
{
class Link;
class IniFile;

std::unique_ptr<Link> createLink(const application::IniFile&);

}

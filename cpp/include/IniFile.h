#pragma once

#include <map>
#include <string>

namespace application
{

class IniFile
{
public:
    IniFile(const std::string&);
    bool hasSection(const std::string&) const;
    bool hasOption(const std::string&, const std::string&) const;
    std::string getOption(const std::string&, const std::string&) const;

private:
    void parse(const std::string&);
    void processSection(const std::string&);
    void processOption(const std::string&);
    bool hasCurrentSection() const;

    std::string m_currentSection;
    std::map<std::string, std::map<std::string, std::string>> m_options;
};

} // namespace application

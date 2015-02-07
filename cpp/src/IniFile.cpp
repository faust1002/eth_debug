#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "IniFile.h"

namespace
{

std::string readContent(const std::string& p_filename)
{
    std::ifstream l_input(p_filename.c_str());
    if (!l_input.is_open())
    {
        throw std::runtime_error("Unable to open config");
    }
    std::ostringstream oss;
    oss << l_input.rdbuf();
    return oss.str();
}

std::vector<std::string> getLines(const std::string& p_content)
{
    const char l_commentIndicator = ';';
    std::regex l_regex(".*[^\\n]");
    auto l_begin = std::sregex_iterator(p_content.begin(), p_content.end(), l_regex);
    auto l_end = std::sregex_iterator();
    std::vector<std::string> l_lines;
    l_lines.reserve(std::distance(l_begin, l_end));
    std::transform(l_begin, l_end, std::back_inserter(l_lines), [](std::sregex_iterator::value_type p_line)
    {
        return p_line.str();
    });
    std::for_each(l_lines.begin(), l_lines.end(), [](std::string& p_line)
    {
        auto l_pos = p_line.find_first_of(l_commentIndicator);
        p_line = p_line.substr(0, l_pos);
    });
    l_lines.erase(std::remove_if(l_lines.begin(), l_lines.end(), [](const std::string& p_line)
    {
        return p_line.empty();
    }), l_lines.end());
    return l_lines;
}

std::smatch prepareMatch(const std::string& p_line, const std::string& p_regex)
{
    std::regex l_regex(p_regex);
    std::smatch l_result;
    std::regex_search(p_line, l_result, l_regex);
    return l_result;
}

} // namespace anonymous

namespace application
{

IniFile::IniFile(const std::string& p_filename)
{
    auto l_content = readContent(p_filename);
    parse(l_content);
}

bool IniFile::hasSection(const std::string& p_sectionName) const
{
    return 1 == m_options.count(p_sectionName);
}

bool IniFile::hasOption(const std::string& p_sectionName, const std::string& p_optionName) const
{
    if (!hasSection(p_sectionName)) return false;
    auto l_options = m_options.at(p_sectionName);
    return 1 == l_options.count(p_optionName);
}

std::string IniFile::getOption(const std::string& p_sectionName, const std::string& p_optionName,
                               const std::string& p_default) const
{
    if (!hasOption(p_sectionName, p_optionName)) return p_default;
    auto l_options = m_options.at(p_sectionName);
    return l_options.at(p_optionName);
}

void IniFile::parse(const std::string& p_content)
{
    auto l_lines = getLines(p_content);
    std::for_each(l_lines.begin(), l_lines.end(), [&](const std::string& p_line)
    {
        processSection(p_line);
        processOption(p_line);
    });
}

void IniFile::processSection(const std::string& p_line)
{
    auto l_result = prepareMatch(p_line, "^\\[([a-z]+)\\]$");
    if (l_result.empty()) return;
    m_currentSection = l_result[1];
}

void IniFile::processOption(const std::string& p_line)
{
    if (!hasCurrentSection()) return;
    auto l_result = prepareMatch(p_line, "^\\s*([a-z]+)\\s*=\\s*(\\S+)\\s*$");
    if (l_result.empty()) return;
    auto l_options = m_options[m_currentSection];
    l_options[l_result[1]] = l_result[2];
    m_options[m_currentSection] = l_options;
}

bool IniFile::hasCurrentSection() const
{
    return !m_currentSection.empty();
}

}

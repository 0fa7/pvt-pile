#pragma once

#include <string>
#include <vector>

class Scanner
{
public:
    static std::vector<std::string> Scan(const std::string& buffer);
private:
    Scanner();
    ~Scanner();
};
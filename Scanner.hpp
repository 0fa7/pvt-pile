#pragma once

#include <string>
#include <vector>

class Token;

class Scanner
{
public:
    static std::vector<Token> Scan(const std::string& buffer);
private:
    Scanner();
    ~Scanner();
};
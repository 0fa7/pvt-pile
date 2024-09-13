#pragma once

#include <string>
#include <memory>
#include <vector>

class IToken;

class Scanner
{
public:
    Scanner(const std::string& buffer);
    ~Scanner();

    std::vector<std::unique_ptr<IToken>> Scan();
    char Peek();
    char Consume();

    int m_current;
    std::string m_buffer;

private:
    Scanner();
};
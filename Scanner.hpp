#pragma once

#include <memory>
#include <string>
#include "Token.hpp"
#include <vector>

class Scanner
{
public:
    Scanner(const std::string& source);
    ~Scanner();

    std::vector<std::unique_ptr<IToken>> ScanTokens();
    void ScanToken();
    bool IsAtEnd();
    char Advance();
    void AddToken(TOKEN_TYPE type);
    void AddToken(TOKEN_TYPE type, const std::string& value);
    bool Match(char expected);
    char Peek();
    void String();

    std::string m_source;
    std::vector<std::unique_ptr<IToken>> m_tokens;
    int m_startPos = 0;
    int m_currentPos = 0;
    int m_line = 1;

private:
    Scanner();
};
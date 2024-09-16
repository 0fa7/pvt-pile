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
    std::vector<std::unique_ptr<IToken>> ScanToken();
    char Peek();
    char Consume();
    bool IsAtEnd();
    char Advance();

    std::string m_source;
    std::vector<std::unique_ptr<IToken>> m_tokens;
    size_t m_startPos;
    size_t m_currentPos;
    size_t m_line;

private:
    Scanner();
};
#include "Scanner.hpp"
#include <memory>

Scanner::Scanner()
{
}

Scanner::Scanner(const std::string& source)
    : m_source(source),
      m_startPos(0),
      m_currentPos(0),
      m_line(1)  
{
}

Scanner::~Scanner()
{
}

std::vector<std::unique_ptr<IToken>> Scanner::ScanTokens()
{
    std::vector<std::unique_ptr<IToken>> tokens;

    while(!IsAtEnd())
    {
        m_startPos = m_currentPos;
        ScanToken();
    }

    tokens.push_back(std::make_unique<Token<int>>(TT_EOF, "", 0, m_line));
    return tokens;
}

std::vector<std::unique_ptr<IToken>> Scanner::ScanToken()
{
    return {};
}

bool Scanner::IsAtEnd()
{
    return m_currentPos >= m_source.length();
}

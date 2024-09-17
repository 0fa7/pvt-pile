#include "Scanner.hpp"
#include "Error.hpp"
#include "TokenType.hpp"
#include <emmintrin.h>
#include <memory>

Scanner::Scanner()
{
}

Scanner::Scanner(const std::string& source)
    : m_source(source)
{
}

Scanner::~Scanner()
{
}

std::vector<std::unique_ptr<IToken>> Scanner::ScanTokens()
{
    while (!IsAtEnd())
    {
        m_startPos = m_currentPos;
        ScanToken();
    }

    AddToken(TT_EOF);
    return std::move(m_tokens);
}

void Scanner::ScanToken()
{
    char c = Advance();

    switch (c)
    {
    case '(':
        AddToken(TT_LEFT_PAREN);
        break;
    case ')':
        AddToken(TT_RIGHT_PAREN);
        break;
    case '{':
        AddToken(TT_LEFT_BRACE);
        break;
    case '}':
        AddToken(TT_RIGHT_BRACE);
        break;
    case ',':
        AddToken(TT_COMMA);
        break;
    case '.':
        AddToken(TT_DOT);
        break;
    case '-':
        AddToken(TT_MINUS);
        break;
    case '+':
        AddToken(TT_PLUS);
        break;
    case ';':
        AddToken(TT_SEMICOLON);
        break;
    case '*':
        AddToken(TT_STAR);
        break;
    case '!':
        AddToken(Match('=') ? TT_BANG_EQUAL : TT_BANG);
        break;
    case '=':
        AddToken(Match('=') ? TT_EQUAL_EQUAL : TT_EQUAL);
        break;
    case '<':
        AddToken(Match('=') ? TT_LESS_EQUAL : TT_LESS);
        break;
    case '>':
        AddToken(Match('=') ? TT_GREATER_EQUAL : TT_GREATER);
        break;
    case '/':
        if(Match('/'))
        {
            while(!IsAtEnd() && Peek() != '\n')
            {
                Advance();
            }
        }
        else
        {
            AddToken(TT_SLASH);
        }

        break;
    case ' ':
    case '\r':
    case '\t':
        break;
    case '\n':
        m_line++;
        break;
    case '"':
        String();
        break;
    default:
        Error(m_line, "Unexpected Character.");
        break;
    }
}

bool Scanner::IsAtEnd()
{
    return m_currentPos >= m_source.length();
}

char Scanner::Advance()
{
    return m_source[m_currentPos++];
}

void Scanner::AddToken(TOKEN_TYPE type)
{
    std::string text = m_source.substr(m_startPos, m_currentPos - m_startPos);
    m_tokens.push_back(std::make_unique<Token<int>>(type, text, 0, m_line));
}

void Scanner::AddToken(TOKEN_TYPE type, const std::string& value)
{
    std::string text = m_source.substr(m_startPos, m_currentPos - m_startPos);
    m_tokens.push_back(std::make_unique<Token<std::string>>(type, text, value, m_line));
}

bool Scanner::Match(char expected)
{
    if(IsAtEnd())
    {
        return false;
    }

    if(m_source[m_currentPos] != expected)
    {
        return false;
    }

    m_currentPos++;
    return true;
}

char Scanner::Peek()
{
    if(IsAtEnd())
    {
        return '\0';
    }

    return m_source[m_currentPos];
}

void Scanner::String()
{
    while(!IsAtEnd() && Peek() != '"')
    {
        if(Peek() == '\n')
        {
            m_line++;
        }

        Advance();
    }

    if(IsAtEnd())
    {
        Error(m_line, "Unterminated string.");
        return;
    }

    Advance();

    std::string value = m_source.substr(m_startPos + 1, m_currentPos - 1 - (m_startPos + 1));
    AddToken(TT_STRING, value);
}
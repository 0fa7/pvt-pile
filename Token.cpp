#include "Token.hpp"

IToken::IToken()
{
}

IToken::IToken(TOKEN_TYPE type, const std::string& lexeme, int line) :
    m_type(type), m_lexeme(lexeme), m_line(line)
{
}

IToken::~IToken()
{
}
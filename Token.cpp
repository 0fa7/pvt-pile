#include "Token.hpp"

IToken::IToken(TOKEN_TYPE type, int line, const std::string& lexeme) :
m_type(type), m_line(line), m_lexeme(lexeme)
{}

IToken::~IToken()
{
}
#pragma once

#include <string>
#include <sstream>
#include "TokenType.hpp"

class IToken
{
public:
    IToken(TOKEN_TYPE type, const std::string& lexeme, int line);
    virtual ~IToken();
    virtual std::string ToString() = 0;

    TOKEN_TYPE m_type;
    std::string m_lexeme;
    int m_line;

private:
    IToken();
};

template<typename T>
class Token : public IToken
{
public:
    Token(TOKEN_TYPE type, const std::string& lexeme, T literal, int line) :
        IToken(type, lexeme, line), m_literal(literal)
    {}
    
    virtual ~Token() override {}
    
    virtual std::string ToString() override
    {
        std::stringstream ss;
        ss << m_type << " " << m_lexeme << " " <<
            std::to_string(m_literal) << " " << m_line;
        return ss.str();
    }

    T m_literal;
private:
    Token() {}
};
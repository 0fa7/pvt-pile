#pragma once

#include <cstdint>
#include <iostream>
#include <string>

enum TOKEN_TYPE : int16_t
{
    TT_LEFT_PAREN = 0,
    TT_RIGHT_PAREN,
    TT_LEFT_BRACE,
    TT_RIGHT_BRACE,
    TT_COMMA,
    TT_DOT,
    TT_MINUS,
    TT_PLUS,
    TT_SEMICOLON,
    TT_SLASH,
    TT_STAR,
    // One or two character tokens.
    TT_BANG,
    TT_BANG_EQUAL,
    TT_EQUAL,
    TT_EQUAL_EQUAL,
    TT_GREATER,
    TT_GREATER_EQUAL,
    TT_LESS,
    TT_LESS_EQUAL,
    // Literals.
    TT_IDENTIFIER,
    TT_STRING,
    TT_NUMBER,
    // Keywords.
    TT_AND,
    TT_CLASS,
    TT_ELSE,
    TT_FALSE,
    TT_FUN,
    TT_FOR,
    TT_IF,
    TT_NIL,
    TT_OR,
    TT_PRINT,
    TT_RETURN,
    TT_SUPER,
    TT_THIS,
    TT_TRUE,
    TT_VAR,
    TT_WHILE,
    TT_EOF
};

class IToken
{
public:
    virtual void Print() = 0;
    ~IToken();

    TOKEN_TYPE m_type;
    std::string m_lexeme;
    int m_line;

//protected:
    IToken(TOKEN_TYPE type, int line, const std::string& lexeme);
};

template<typename T>
class Token : public IToken
{
public:
    Token(TOKEN_TYPE type, const std::string& lexeme, int line, T literal) :
    IToken(type, line, lexeme), m_literal(literal)
    {}

    ~Token() {};
    
    virtual void Print() override
    {
        std::cout << m_type << " " << m_line << " " << m_lexeme << " " << m_literal << std::endl;
    }
    
    T m_literal;

private:
    Token();
};
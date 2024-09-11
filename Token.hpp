#pragma once

#include <cstdint>

enum TOKEN_TYPE : int16_t
{
    TT_NUMBER = 0,
    TT_STRING,
    TT_TRUE,
    TT_FALSE,
    TT_NIL,
    TT_MINUS,
    TT_BANG,
    TT_EQUAL_EQUAL,
    TT_BANG_EQUAL,
    TT_LESS_THAN,
    TT_LESS_THAN_EQUAL,
    TT_GREATER_THAN,
    TT_GREATER_THAN_EQUAL,
    TT_PLUS,
    TT_STAR,
    TT_SLASH,
};

class Token
{
public:
    Token(TOKEN_TYPE type);
    ~Token();

    TOKEN_TYPE m_type;

private:
    Token();
    
};
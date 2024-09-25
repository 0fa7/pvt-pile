#include "Parser.hpp"
#include "Expr.hpp"
#include "Token.hpp"
#include "TokenType.hpp"

Parser::Parser()
{
}

Parser::Parser(const std::vector<IToken*>& tokens) :
    m_tokens(tokens)
{
}

Parser::~Parser()
{
}

IExpr* Parser::Expression()
{
    return Equality();
}

IExpr* Parser::Equality()
{
    IExpr* expr = Comparison();

    while(Match({TT_BANG_EQUAL, TT_EQUAL_EQUAL}))
    {
        IToken* op = Previous();
        IExpr* right = Comparison();
        expr = new Binary(expr, op, right);
    }

    return expr;
}

IExpr* Parser::Comparison()
{
    IExpr* expr = Term();

    while(Match({TT_GREATER, TT_GREATER_EQUAL, TT_LESS, TT_LESS_EQUAL}))
    {
        IToken* op = Previous();
        IExpr* right = Term();
        expr = new Binary(expr, op, right);
    }

    return expr;
}

bool Parser::Match(const std::vector<TOKEN_TYPE>& types)
{
    for(const auto& type : types)
    {
        if(Check(type))
        {
            Advance();
            return true;
        }
    }

    return false;
}

bool Parser::Check(const TOKEN_TYPE& type)
{
    if(IsAtEnd())
    {
        return false;
    }

    return Peek()->m_type == type;
}

IToken* Parser::Advance()
{
    if(!IsAtEnd())
    {
        m_current++;
    }

    return Previous();
}

bool Parser::IsAtEnd()
{
    return Peek()->m_type == EOF;
}

IToken* Parser::Peek()
{
    return m_tokens[m_current];
}

IToken* Parser::Previous()
{
    return m_tokens[m_current - 1];
}

IExpr* Parser::Term()
{
    IExpr* expr = Factor();

    while(Match({TT_MINUS, TT_PLUS}))
    {
        IToken* op = Previous();
        IExpr* right = Factor();
        expr = new Binary(expr, op, right);
    }

    return expr;
}

IExpr* Parser::Factor()
{
    IExpr* expr = this->Unary();

    while(Match({TT_SLASH, TT_STAR}))
    {
        IToken* op = Previous();
        IExpr* right = this->Unary();
        expr = new Binary(expr, op, right);
    }

    return expr;
}

IExpr* Parser::Unary()
{
    if(Match({TT_BANG, TT_MINUS}))
    {
        IToken* op = Previous();
        IExpr* right = this->Unary();
        return new class Unary(op, right);
    }

    return Primary();
}

IExpr* Parser::Primary()
{
    if(Match({TT_FALSE}))
    {
        
    }


    return nullptr;
}
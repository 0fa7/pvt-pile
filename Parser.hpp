#pragma once

#include "Expr.hpp"
#include "TokenType.hpp"
#include <memory>
#include <vector>

class IExpr;
class IToken;

class Parser
{
public:
    Parser();
    Parser(const std::vector<IToken*>& tokens);
    ~Parser();

    std::vector<IToken*> m_tokens;
    int m_current = 0;

    IExpr* Expression();
    IExpr* Equality();
    IExpr* Comparison();
    bool Match(const std::vector<TOKEN_TYPE>& types);
    bool Check(const TOKEN_TYPE& type);
    IToken* Advance();
    bool IsAtEnd();
    IToken* Peek();
    IToken* Previous();
    IExpr* Term();
    IExpr* Factor();
    IExpr* Unary();
    IExpr* Primary();
};
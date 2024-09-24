#pragma once

#include "UniqueVoidPtr.hpp"

class IToken;
class IVisitor;

class IExpr
{
  public:
    IExpr();
    ~IExpr();

    virtual UniqueVoidPtr Accept(IVisitor* visitor);
};

class Binary : public IExpr
{
  public:
    Binary();
    Binary(IExpr* left, IToken* op, IExpr* right);
    ~Binary();

    virtual UniqueVoidPtr Accept(IVisitor* visitor) override;

    IExpr* m_left = nullptr;
    IToken* m_operator = nullptr;
    IExpr* m_right = nullptr;
};

class Grouping : public IExpr
{
  public:
    Grouping();
    Grouping(IExpr* expr);
    ~Grouping();

    virtual UniqueVoidPtr Accept(IVisitor* visitor) override;

    IExpr* m_expr = nullptr;
};

class Literal : public IExpr
{
  public:
    Literal();
    Literal(IToken* object);
    ~Literal();

    virtual UniqueVoidPtr Accept(IVisitor* visitor) override;

    IToken* m_object = nullptr;
};

class Unary : public IExpr
{
  public:
    Unary();
    Unary(IToken* op, IExpr* right);
    ~Unary();

    virtual UniqueVoidPtr Accept(IVisitor* visitor) override;

    IToken* m_operator = nullptr;
    IExpr* m_right = nullptr;
};
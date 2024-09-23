#pragma once

#include <memory>
#include "ExprVisitor.hpp"

class IToken;

class IExpr
{
  public:
    IExpr(std::unique_ptr<IExpr> left, std::unique_ptr<IToken> op, std::unique_ptr<IExpr> right);
    virtual ~IExpr();
    // virtual void Accept(ExprVisitor visitor) = 0;

    std::unique_ptr<IExpr> m_left;
    std::unique_ptr<IToken> m_op;
    std::unique_ptr<IExpr> m_right;

  private:
    IExpr();
};

class Binary : public IExpr
{
  public:
    Binary(std::unique_ptr<IExpr> left, std::unique_ptr<IToken> op, std::unique_ptr<IExpr> right);
    virtual ~Binary() override;
    // virtual void Accept(ExprVisitor visitor) override;
    template <typename T, typename R> R Accept(T* visitor)
    {
        return visitor->VisitBinary(*this);
    }
};


class Grouping : public IExpr
{
  public:
    Grouping(std::unique_ptr<IExpr> expr);
    virtual ~Grouping() override;
    // virtual void Accept(ExprVisitor visitor) override;
};

class Literal : public IExpr
{
  public:
    Literal(std::unique_ptr<IToken> literal);
    virtual ~Literal() override;
    // virtual void Accept(ExprVisitor visitor) override;
};

class Unary : public IExpr
{
  public:
    Unary(std::unique_ptr<IToken> op, std::unique_ptr<IExpr> right);
    virtual ~Unary() override;
    // virtual void Accept(ExprVisitor visitor) override;
};

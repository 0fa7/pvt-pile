#pragma once

#include "ExprVisitor.hpp"
#include <memory>

class IToken;

class IExpr
{
  public:
    IExpr(std::unique_ptr<IExpr> left, std::unique_ptr<IToken> op, std::unique_ptr<IExpr> right);
    virtual ~IExpr();

    template <typename T, typename R> R Accept(T* visitor)
    {
      static_cast<T*>(visitor);
      return R{};
    }

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

    template <typename T, typename R> R Accept(T* visitor)
    {
        return visitor->VisitGrouping(*this);
    }
};

class Literal : public IExpr
{
  public:
    Literal(std::unique_ptr<IToken> literal);
    virtual ~Literal() override;

    template <typename T, typename R> R Accept(T* visitor)
    {
        return visitor->VisitLiteral(*this);
    }
};

class Unary : public IExpr
{
  public:
    Unary(std::unique_ptr<IToken> op, std::unique_ptr<IExpr> right);
    virtual ~Unary() override;

    template <typename T, typename R> R Accept(T* visitor)
    {
        return visitor->VisitUnary(*this);
    }
};

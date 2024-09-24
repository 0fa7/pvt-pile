#pragma once

class IToken;
class IVisitor;

class IExpr
{
  public:
    IExpr();
    ~IExpr();

    virtual void* Accept(IVisitor* visitor);
};

class Binary : public IExpr
{
  public:
    Binary();
    Binary(IExpr* left, IToken* op, IExpr* right);
    ~Binary();

    virtual void* Accept(IVisitor* visitor) override;

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

    virtual void* Accept(IVisitor* visitor) override;

    IExpr* m_expr = nullptr;
};

class Literal : public IExpr
{
  public:
    Literal();
    Literal(void* object);
    ~Literal();

    virtual void* Accept(IVisitor* visitor) override;

    void* m_object = nullptr;
};

class Unary : public IExpr
{
  public:
    Unary();
    Unary(IToken* op, IExpr* right);
    ~Unary();

    virtual void* Accept(IVisitor* visitor) override;

    IToken* m_operator = nullptr;
    IExpr* m_right = nullptr;
};
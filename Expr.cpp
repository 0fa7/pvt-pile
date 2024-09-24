#include "Expr.hpp"
#include "ExprVisitor.hpp"

IExpr::IExpr()
{
}

IExpr::~IExpr()
{
}

void* IExpr::Accept(IVisitor* visitor)
{
    return nullptr;
}

Binary::Binary()
{
}

Binary::Binary(IExpr* left, IToken* op, IExpr* right)
    : m_left(left),
      m_operator(op),
      m_right(right)
{
}

Binary::~Binary()
{
}

void* Binary::Accept(IVisitor* visitor)
{
    return visitor->VisitBinary(this);
}

Grouping::Grouping()
{
}

Grouping::Grouping(IExpr* expr)
    : m_expr(expr)
{
}

Grouping::~Grouping()
{
}

void* Grouping::Accept(IVisitor* visitor)
{
    return visitor->VisitGrouping(this);
}

Literal::Literal()
{
}

Literal::Literal(IToken* object)
    : m_object(object)
{
}

Literal::~Literal()
{
}

void* Literal::Accept(IVisitor* visitor)
{
    return visitor->VisitLiteral(this);
}

Unary::Unary()
{
}

Unary::Unary(IToken* op, IExpr* right) :
    m_operator(op), m_right(right)
{
}

Unary::~Unary()
{
}

void* Unary::Accept(IVisitor* visitor)
{
    return visitor->VisitUnary(this);
}
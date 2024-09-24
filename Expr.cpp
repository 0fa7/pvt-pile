#include "Expr.hpp"
#include "ExprVisitor.hpp"
#include "UniqueVoidPtr.hpp"

IExpr::IExpr()
{
}

IExpr::~IExpr()
{
}

UniqueVoidPtr IExpr::Accept(IVisitor* visitor)
{

    return MakeUniqueVoidPtr(new int(0));
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

UniqueVoidPtr Binary::Accept(IVisitor* visitor)
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

UniqueVoidPtr Grouping::Accept(IVisitor* visitor)
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

UniqueVoidPtr Literal::Accept(IVisitor* visitor)
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

UniqueVoidPtr Unary::Accept(IVisitor* visitor)
{
    return visitor->VisitUnary(this);
}
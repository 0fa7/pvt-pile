#include "ExprVisitor.hpp"
#include "Expr.hpp"
#include "UniqueVoidPtr.hpp"
#include <memory>
#include <string>

IVisitor::IVisitor()
{
}

IVisitor::~IVisitor()
{
}

VisitorEx::VisitorEx()
{
}
VisitorEx::~VisitorEx()
{
}

UniqueVoidPtr VisitorEx::Call(IExpr* expr)
{
    auto res = MakeUniqueVoidPtr(new std::string("VisitorEx::Call"));
    return res;
}

UniqueVoidPtr VisitorEx::VisitBinary(Binary* expr)
{
    auto res = MakeUniqueVoidPtr(new std::string("VisitorEx::VisitBinary"));
    return res;
}

UniqueVoidPtr VisitorEx::VisitGrouping(Grouping* expr)
{
    auto res = MakeUniqueVoidPtr(new std::string("VisitorEx::VisitGrouping"));
    return res;
}

UniqueVoidPtr VisitorEx::VisitLiteral(Literal* expr)
{
    auto res = MakeUniqueVoidPtr(new std::string("VisitorEx::VisitLiteral"));
    return res;
}

UniqueVoidPtr VisitorEx::VisitUnary(Unary* expr)
{
    auto res = MakeUniqueVoidPtr(new std::string("VisitorEx::VisitUnary"));
    return res;
}

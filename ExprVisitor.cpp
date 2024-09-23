#include "ExprVisitor.hpp"
#include "Expr.hpp"
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

void* VisitorEx::Call(IExpr* expr)
{
    return expr->Accept(this);
}

void* VisitorEx::VisitBinary(Binary* expr)
{
    std::string* res = new std::string("VisitBinary");
    return static_cast<void*>(res);
}

void* VisitorEx::VisitGrouping(Grouping* expr)
{
    std::string* res = new std::string("VisitGroupingExpr");
    return static_cast<void*>(res);
}

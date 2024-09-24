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

UniqueVoidPtr VisitorEx::Call2(IExpr* expr)
{
    UniqueVoidPtr str(new std::string("World"), VoidPtrDeleter<std::string>);   
    return str;
}

std::shared_ptr<void> VisitorEx::Call(IExpr* expr)
{
    auto res = std::shared_ptr<std::string>(new std::string("VisitorEx::Call"));
    
    return res;
}

void* VisitorEx::VisitBinary(Binary* expr)
{
    //std::unique_ptr<void> res(new std::string("VisitBinary"));
    //return res;
    return {};
}

void* VisitorEx::VisitGrouping(Grouping* expr)
{
    //std::unique_ptr<void> res(new std::string("VisitGrouping"));
    //return res;
    return {};
}

void* VisitorEx::VisitLiteral(Literal* expr)
{
    //std::unique_ptr<void> res(new std::string("VisitLiteral"));
    //return res;
    return {};
}

void* VisitorEx::VisitUnary(Unary* expr)
{
    //std::unique_ptr<void> res(new std::string("VisitUnary"));
    //return res;
    return {};
}

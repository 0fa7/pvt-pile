#pragma once

#include "UniqueVoidPtr.hpp"
#include <string>

class IExpr;
class Binary;
class Grouping;
class Literal;
class Unary;

class IVisitor
{
  public:
    IVisitor();
    ~IVisitor();

    virtual void* VisitBinary(Binary* expr) = 0;
    virtual void* VisitGrouping(Grouping* expr) = 0;
    virtual void* VisitLiteral(Literal* expr) = 0;
    virtual void* VisitUnary(Unary* expr) = 0;
};

class VisitorEx : public IVisitor
{
  public:
    VisitorEx();
    ~VisitorEx();

    UniqueVoidPtr Call2(IExpr* expr);
    std::shared_ptr<void> Call(IExpr* expr);
    virtual void* VisitBinary(Binary* expr) override;
    virtual void* VisitGrouping(Grouping* expr) override;
    virtual void* VisitLiteral(Literal* expr) override;
    virtual void* VisitUnary(Unary* expr) override;
};
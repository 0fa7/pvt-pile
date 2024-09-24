#pragma once

#include "UniqueVoidPtr.hpp"

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

    virtual UniqueVoidPtr VisitBinary(Binary* expr) = 0;
    virtual UniqueVoidPtr VisitGrouping(Grouping* expr) = 0;
    virtual UniqueVoidPtr VisitLiteral(Literal* expr) = 0;
    virtual UniqueVoidPtr VisitUnary(Unary* expr) = 0;
};

class VisitorEx : public IVisitor
{
  public:
    VisitorEx();
    ~VisitorEx();

    UniqueVoidPtr Call(IExpr* expr);
    virtual UniqueVoidPtr VisitBinary(Binary* expr) override;
    virtual UniqueVoidPtr VisitGrouping(Grouping* expr) override;
    virtual UniqueVoidPtr VisitLiteral(Literal* expr) override;
    virtual UniqueVoidPtr VisitUnary(Unary* expr) override;
};
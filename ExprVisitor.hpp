#pragma once

class IExpr;
class Binary;
class Grouping;

class IVisitor
{
  public:
    IVisitor();
    ~IVisitor();

    virtual void* VisitBinary(Binary* expr) = 0;
    virtual void* VisitGrouping(Grouping* expr) = 0;
};

class VisitorEx : public IVisitor
{
  public:
    VisitorEx();
    ~VisitorEx();

    void* Call(IExpr* expr);
    virtual void* VisitBinary(Binary* expr) override;
    virtual void* VisitGrouping(Grouping* expr) override;
};
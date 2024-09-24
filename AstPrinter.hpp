#pragma once

#include "ExprVisitor.hpp"
#include <memory>
#include <string>
#include <vector>

class AstPrinter : public IVisitor
{
public:
    AstPrinter();
    ~AstPrinter();

    std::unique_ptr<std::string> Print(IExpr* expr);
    virtual void* VisitBinary(Binary* expr) override;
    virtual void* VisitGrouping(Grouping* expr) override;
    virtual void* VisitLiteral(Literal* expr) override;
    virtual void* VisitUnary(Unary* expr) override;
    std::string Parenthesize(const std::string& name, const std::vector<IExpr*> exprs);
};
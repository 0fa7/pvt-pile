#pragma once

#include "ExprVisitor.hpp"
#include "UniqueVoidPtr.hpp"
#include <string>
#include <vector>

class AstPrinter : public IVisitor
{
public:
    AstPrinter();
    ~AstPrinter();

    std::unique_ptr<std::string> Print(IExpr* expr);
    virtual UniqueVoidPtr VisitBinary(Binary* expr) override;
    virtual UniqueVoidPtr VisitGrouping(Grouping* expr) override;
    virtual UniqueVoidPtr VisitLiteral(Literal* expr) override;
    virtual UniqueVoidPtr VisitUnary(Unary* expr) override;
    std::string Parenthesize(const std::string& name, const std::vector<IExpr*> exprs);
};
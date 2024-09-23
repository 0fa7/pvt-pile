#pragma once

#include "ExprVisitor.hpp"
#include <string>

class AstPrinter : public BaseVisitor<AstPrinter, std::string>
{
public:
    AstPrinter();
    ~AstPrinter();

    std::string Print(IExpr* expr);
    std::string VisitBinary(Binary& binary);
    std::string VisitGrouping(Grouping& binary);
    std::string VisitLiteral(Literal& binary);
    std::string VisitUnary(Unary& binary);
};
#include "AstPrinter.hpp"
#include "Expr.hpp"

AstPrinter::AstPrinter()
{
}

AstPrinter::~AstPrinter()
{
}

std::string AstPrinter::Print(IExpr* expr)
{
    expr->Accept<AstPrinter, std::string>(this);
    return "test";
}

std::string AstPrinter::VisitBinary(Binary& binary)
{
    return "AstPrinter::VisitBinary";
}

std::string AstPrinter::VisitGrouping(Grouping& binary)
{
    return "AstPrinter::VisitGrouping";
}

std::string AstPrinter::VisitLiteral(Literal& binary)
{
    return "AstPrinter::VisitLiteral";
}

std::string AstPrinter::VisitUnary(Unary& binary)
{
    return "AstPrinter::VisitUnary";
}
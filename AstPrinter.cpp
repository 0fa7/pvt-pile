#include "AstPrinter.hpp"
#include "Expr.hpp"
#include <sstream>

AstPrinter::AstPrinter()
{
}

AstPrinter::~AstPrinter()
{
}

std::unique_ptr<std::string> AstPrinter::Print(IExpr* expr)
{
    std::unique_ptr<std::string> res(static_cast<std::string*>(expr->Accept(this)));
    return res;
}

void* AstPrinter::VisitBinary(Binary* expr)
{
    return nullptr;
}

void* AstPrinter::VisitGrouping(Grouping* expr)
{
    return nullptr;
}

void* AstPrinter::VisitLiteral(Literal* expr)
{
    return nullptr;
}

void* AstPrinter::VisitUnary(Unary* expr)
{
    return nullptr;
}

std::string AstPrinter::Parenthesize(const std::string& name, const std::vector<IExpr*> exprs)
{
    return "";
}
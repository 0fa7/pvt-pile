#include "AstPrinter.hpp"
#include "Expr.hpp"
#include <memory>
#include <regex>
#include <sstream>
#include "Token.hpp"

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
    std::string* res = new std::string(Parenthesize(expr->m_operator->m_lexeme, {expr->m_left, expr->m_right}));
    return static_cast<void*>(res);
}

void* AstPrinter::VisitGrouping(Grouping* expr)
{
    std::string* res = new std::string(Parenthesize("group", {expr->m_expr}));
    return static_cast<void*>(res);
}

void* AstPrinter::VisitLiteral(Literal* expr)
{
    std::string* res = new std::string("nil");

    if(expr->m_object)
    {
        *res = "literal";
    }

    return static_cast<void*>(res);
}

void* AstPrinter::VisitUnary(Unary* expr)
{
    std::string* res = new std::string(Parenthesize(expr->m_operator->m_lexeme, {expr->m_right}));
    return static_cast<void*>(res);
}

std::string AstPrinter::Parenthesize(const std::string& name, const std::vector<IExpr*> exprs)
{
    std::stringstream ss;
    ss << "(" << name;

    for(auto* expr : exprs)
    {
        ss << " ";
        auto res = expr->Accept(this);
        ss << *static_cast<std::string*>(res);
    }

    ss << ")";

    return ss.str();
}
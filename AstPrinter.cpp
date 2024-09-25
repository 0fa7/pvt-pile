#include "AstPrinter.hpp"
#include "Expr.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>
#include "Token.hpp"
#include "TokenType.hpp"
#include "UniqueVoidPtr.hpp"

AstPrinter::AstPrinter()
{
}

AstPrinter::~AstPrinter()
{
}

std::unique_ptr<std::string> AstPrinter::Print(IExpr* expr)
{
    auto res = *static_cast<std::string*>(expr->Accept(this).get());
    return std::unique_ptr<std::string>(new std::string (res));
}

UniqueVoidPtr AstPrinter::VisitBinary(Binary* expr)
{
    auto res = Parenthesize(expr->m_operator->m_lexeme, {expr->m_left, expr->m_right});
    return res;
}

UniqueVoidPtr AstPrinter::VisitGrouping(Grouping* expr)
{
    auto res = Parenthesize("group", {expr->m_expr});
    return res;
}

UniqueVoidPtr AstPrinter::VisitLiteral(Literal* expr)
{
    std::stringstream ss;

    if(expr->m_object->m_type == TT_NUMBER)
    {   
        Token<double>* t = reinterpret_cast<Token<double>*>(expr->m_object);
        ss << t->m_literal;
    }
    else if(expr->m_object->m_type == TT_IDENTIFIER || expr->m_object->m_type == TT_STRING)
    {        
        Token<std::string>* t = reinterpret_cast<Token<std::string>*>(expr->m_object);
        ss << t->m_literal;
    }
    else
    {
        ss << "nil";
    }

    return MakeUniqueVoidPtr(new std::string(ss.str()));
}

UniqueVoidPtr AstPrinter::VisitUnary(Unary* expr)
{
    auto res = Parenthesize(expr->m_operator->m_lexeme, {expr->m_right});
    return res;
}

UniqueVoidPtr AstPrinter::Parenthesize(const std::string& name, const std::vector<IExpr*> exprs)
{
    std::stringstream ss;

    ss << "(" << name;

    for(auto* expr : exprs)
    {
        ss << " ";
        auto sub = expr->Accept(this);
        ss << *static_cast<std::string*>(sub.get());
    }

    ss << ")";

    return MakeUniqueVoidPtr(new std::string(ss.str()));
}
#pragma once
#include "Expr.hpp"
#include <iostream>

class Binary;
class Grouping;
class Literal;
class Unary;

template <class T, typename R> class BaseVisitor
{
  public:
    BaseVisitor()
    {
    }
    ~BaseVisitor()
    {
    }

    R VisitBinary(Binary& binary)
    {
        return static_cast<T*>(this)->VisitBinary(binary);
    }

    R VisitGrouping(Grouping& grouping)
    {
        return static_cast<T*>(this)->VisitGrouping(grouping);
    }

    R VisitLiteral(Literal& literal)
    {
        return static_cast<T*>(this)->VisitLiteral(literal);
    }

    R VisitUnary(Unary& unary)
    {
        return static_cast<T*>(this)->VisitUnary(unary);
    }
};

template <typename R> class ExprVisitor : public BaseVisitor<ExprVisitor<R>, R>
{
  public:
    ExprVisitor()
    {
    }

    ~ExprVisitor()
    {
    }

    R VisitBinary(Binary& binary)
    {
        std::cout << "ExprVisitor::VisitBinary" << std::endl;
        return R{};
    }

    R VisitGrouping(Grouping& binary)
    {
        std::cout << "ExprVisitor::VisitGrouping" << std::endl;
        return R{};
    }

    R VisitLiteral(Literal& binary)
    {
        std::cout << "ExprVisitor::VisitLiteral" << std::endl;
        return R{};
    }

    R VisitUnary(Unary& binary)
    {
        std::cout << "ExprVisitor::VisitUnary" << std::endl;
        return R{};
    }
};
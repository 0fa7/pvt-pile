#pragma once

class Binary;
class Grouping;
class Literal;
class Unary;

class ExprVisitor
{
public:
    ExprVisitor();
    ~ExprVisitor();
    void VisitBinary(Binary& binary);
    void VisitGrouping(Grouping& object);
    void VisitLiteral(Literal& object);
    void VisitUnary(Unary& object);
};
#include "AstPrinter.hpp"
#include "Error.hpp"
#include "Expr.hpp"
#include "ExprVisitor.hpp"
#include "Scanner.hpp"
#include "Token.hpp"
#include "TokenType.hpp"
#include <fstream>
#include <iostream>
#include <string>

void Run(std::string source)
{
    Scanner s(source);
    auto tokens = s.ScanTokens();
}

void RunFile(char* fileName)
{
    std::ifstream ifs(fileName);

    if (ifs.good())
    {
        std::string buf;
        ifs >> buf;
        Run(buf);
    }
    else
    {
        std::cout << "Invalid file: " << fileName << std::endl;
    }
}

void RunPrompt()
{
    std::string line;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, line);

        if (line == "")
        {
            break;
        }

        Run(line);

        hadError = false;
    }
}

int main(int argc, char** argv)
{
    VisitorEx v;
    AstPrinter a;
    IExpr* be = new Binary();
    IExpr* ge = new Grouping();
    IExpr* le = new Literal();
    IExpr* ue = new Unary();

    IExpr* expression = new Binary(
        new Unary(new Token<int>(TT_MINUS, "-", 0, 1), new Literal(new Token<double>(TT_NUMBER, "123", 123, 1))),
        new Token<int>(TT_STAR, "*", 0, 1), new Grouping(new Literal(new Token<double>(TT_NUMBER, "45.67", 45.67, 1))));

    auto bb = v.VisitBinary(static_cast<Binary*>(be));
    auto gb = v.VisitGrouping(static_cast<Grouping*>(ge));
    auto lb = v.VisitLiteral(static_cast<Literal*>(le));
    auto ub = v.VisitUnary(static_cast<Unary*>(ue));
    auto p = a.Print(expression);

    std::cout << "void* cast: " << *static_cast<std::string*>(bb.get()) << std::endl;
    std::cout << "void* cast: " << *static_cast<std::string*>(gb.get()) << std::endl;
    std::cout << "void* cast: " << *static_cast<std::string*>(lb.get()) << std::endl;
    std::cout << "void* cast: " << *static_cast<std::string*>(ub.get()) << std::endl;
    std::cout << "void* cast: " << *static_cast<std::string*>(p.get()) << std::endl;

    if (argc > 2)
    {
        std::cout << "Usage: pvt_pile [script]" << std::endl;
    }
    else if (argc == 2)
    {
        RunFile(argv[1]);
    }
    else
    {
        RunPrompt();
    }
}
#include "AstPrinter.hpp"
#include "Error.hpp"
#include <cstddef>
#include <fstream>
#include <iostream>
#include "Expr.hpp"
#include "ExprVisitor.hpp"
#include "Scanner.hpp"
#include <string>

void Run(std::string source)
{
    Scanner s(source);
    auto tokens = s.ScanTokens();

    for(auto& token : tokens)
    {
        //token->Print();
    }    
}

void RunFile(char* fileName)
{
    std::ifstream ifs(fileName);

    if(ifs.good())
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
    Binary b(nullptr, nullptr, nullptr);
    Grouping g(nullptr);
    Literal l(nullptr);
    Unary u(nullptr, nullptr);

    ExprVisitor<int> ex;
    AstPrinter ap;

    int i = b.Accept<decltype(ex), int>(&ex);
    g.Accept<decltype(ex), int>(&ex);
    l.Accept<decltype(ex), int>(&ex);
    u.Accept<decltype(ex), int>(&ex);
    IExpr ie(nullptr, nullptr, nullptr);

    std::cout << b.Accept<decltype(ap), std::string>(&ap) << std::endl;
    std::cout << g.Accept<decltype(ap), std::string>(&ap) << std::endl;
    std::cout << l.Accept<decltype(ap), std::string>(&ap) << std::endl;
    std::cout << u.Accept<decltype(ap), std::string>(&ap) << std::endl;
    std::cout << i << std::endl;
    
    std::cout << ap.Print(&ie) << std::endl;

    if(argc > 2)
    {
        std::cout << "Usage: pvt_pile [script]" << std:: endl;
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
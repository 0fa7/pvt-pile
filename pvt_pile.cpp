#include "AstPrinter.hpp"
#include "Error.hpp"
#include <fstream>
#include <iostream>
#include "Expr.hpp"
#include "ExprVisitor.hpp"
#include "Scanner.hpp"
#include <memory>
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
    VisitorEx v;
    AstPrinter a;
    IExpr* expr = new Binary();

    std::unique_ptr<std::string> s(static_cast<std::string*>(v.Call(expr)));
    
    std::cout << "void* cast: " << *s << std::endl;

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
#include "Repl.hpp"
#include <iostream>
#include <string>

Repl::Repl()
{
}

Repl::~Repl()
{
}

void Repl::Run()
{
    std::string line{""};
    
    while(line != "quit")
    {
        std::cout << "> ";
        std::getline(std::cin, line);
        std::cout << line << std::endl;
    }
}
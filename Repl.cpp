#include "Repl.hpp"
#include "Scanner.hpp"
#include <iostream>
#include <string>
#include "Token.hpp"

Repl::Repl() {}

Repl::~Repl() {}

void Repl::Run()
{
    std::string line{""};

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, line);

        if (line == "quit")
        {
            break;
        }
        Scanner s(line);
        auto tokens = s.Scan();

        for(const auto& tok : tokens)
        {
            tok->Print();
        }
    }
}
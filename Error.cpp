#include "Error.hpp"
#include <iostream>

void Report(int line, const std::string& where, const std::string& message)
{
    std::cout << "[line " << line << "] Error " << where << ": " << message << std::endl;
    hadError = true;
}

void Error(int line, const std::string& message)
{
    Report(line, "", message);
}
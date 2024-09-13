#include "Scanner.hpp"
#include <iostream>
#include "Token.hpp"

Scanner::Scanner() {}

Scanner::Scanner(const std::string& buffer) : m_buffer(buffer), m_current(0) {}

Scanner::~Scanner() {}

std::vector<std::unique_ptr<IToken>> Scanner::Scan()
{
    std::cout << m_buffer << std::endl;
    return {};
}
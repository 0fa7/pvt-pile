#pragma once

#include <memory>
#include <string>
#include "Token.hpp"
#include "TokenType.hpp"
#include <unordered_map>
#include <vector>

class Scanner
{
public:
    Scanner(const std::string& source);
    ~Scanner();

    std::vector<std::unique_ptr<IToken>> ScanTokens();
    void ScanToken();
    bool IsAtEnd();
    char Advance();
    void AddToken(TOKEN_TYPE type);
    template<typename T>
    void AddToken(TOKEN_TYPE type, const T& value);
    bool Match(char expected);
    char Peek();
    void String();
    bool IsDigit(char c);
    void Number();
    char PeekNext();
    bool IsAlpha(char c);
    void Identifier();
    bool IsAlphaNumeric(char c);

    std::string m_source;
    std::vector<std::unique_ptr<IToken>> m_tokens;
    int m_startPos = 0;
    int m_currentPos = 0;
    int m_line = 1;
    std::unordered_map<std::string, TOKEN_TYPE> m_keywords
    {
        {"and", TT_AND},
        {"class", TT_CLASS},
        {"else", TT_ELSE},
        {"false", TT_FALSE},
        {"for", TT_FOR},
        {"fun", TT_FUN},
        {"if", TT_IF},
        {"nil", TT_NIL},
        {"or", TT_OR},
        {"print", TT_PRINT},
        {"return", TT_RETURN},
        {"super", TT_SUPER},
        {"this", TT_THIS},
        {"true", TT_TRUE},
        {"var", TT_VAR},
        {"while", TT_WHILE}
    };

private:
    Scanner();
};
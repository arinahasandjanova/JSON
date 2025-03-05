#ifndef PARSERJSON_TOKENIZER_H
#define PARSERJSON_TOKENIZER_H

#include <string>
#include <iostream>
#include <fstream>

enum class TOKEN
{
    CURLY_OPEN,
    CURLY_CLOSE,
    COLON,
    STRING,
    NUMBER,
    ARRAY_OPEN,
    ARRAY_CLOSE,
    COMMA,
    BOOLEAN,
    NULL_TYPE
};

struct Token {
    std::string value;
    TOKEN type;
    std::string toString();
};

class Tokenizer {
private:
    std::fstream file;
    size_t prevPos;
public:
    Tokenizer(std::string fileName);
    auto getWithoutWhiteSpace()->char;
    auto getToken()->Token;
    auto hasMoreTokens();
    void rollBackToken();
};
#endif //PARSERJSON_TOKENIZER_H
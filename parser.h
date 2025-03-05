#ifndef PARSERJSON_PARSER_H
#define PARSERJSON_PERSER_H

#include "tokenizer.h"
#include "json.h"
#include <memory>

class JSONParser {
private:
    std::fstream file;
    std::shared_ptr<JSON_Node> root;
    std::unique_ptr<JSON_Node> current;
    Tokenizer tokenizer;
public:
    JSONParser(const std::string fileName): tokenizer(fileName){}
    void parse();
    std::shared_ptr<JSON_Node> parseObject();
    std::shared_ptr<JSON_Node> parseString();
    std::shared_ptr<JSON_Node> parseNumber();
    std::shared_ptr<JSON_Node> parseList();
    std::shared_ptr<JSON_Node> parseBoolean();
    std::shared_ptr<JSON_Node> parseNull();
};

#endif //PARSERJSON_PARSER
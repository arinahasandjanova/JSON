#include <iostream>
#include <memory>
#include <vector>
#include <map>
class JSON_Node;
using JSONObject = std::map<std::string, std::shared_ptr<JSON_Node>>;
using JSONList = std::vector<std::shared_ptr<JSON_Node>>;
class JSON_Node {
    enum class Type {OBJECT, LIST, STRING, NUMBER, BOOLEAN, NULL_TYPE};
    union Values {
        JSONObject* object;
        JSONList* list;
        std::string* s;
        float fValue;
        bool bValue;
    } value;
    Type type;
public:
    auto returnObject() {
        if(type == Type::OBJECT) {
            return *value.object;
        }
        throw std::logic_error("Wrong return");
    }
    auto returnList() {
        if(type == Type::LIST) {
            return *value.list;
        }
        throw std::logic_error("Wrong return");
    }
    auto returnString() {
        if(type == Type::STRING) {
            return *value.s;
        }
        throw std::logic_error("Wrong return");
    }
    auto returnFloat() {
        if(type == Type::NUMBER) {
            return value.fValue;
        }
        throw std::logic_error("Wrong return");
    }
    auto returnBool() {
        if(type == Type::BOOLEAN) {
            return value.bValue;
        }
        throw std::logic_error("Wrong return");
    }
    void setObject (JSONObject* object) {
        this->value.object = object;
        type=Type::OBJECT;
    }
    void setList(JSONList* list) {
        this->value.list = list;
        type=Type::LIST;
    }
    void setString(std::string* string) {
        this->value.s = string;
        type=Type::STRING;
    }
    void setFloat(float fnum) {
        this->value.fValue = fnum;
        type=Type::NUMBER;
    }
    void setBool(bool bnum) {
        this->value.bValue = bnum;
        type=Type::BOOLEAN;
    }
};


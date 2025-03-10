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
    void setNull() {
        type=Type::NULL_TYPE;
    }
    std::string toString(int indentLevel) {
        std::string outputString = " ";
        std::string spaceStr = std::to_string(indentLevel*' ');
        switch(type) {
            case Type::STRING:
                outputString+=(spaceStr+*value.s);
                break;
            case Type::NUMBER:
                outputString+=(spaceStr+std::to_string(value.fValue));
                break;
            case Type::BOOLEAN:
                outputString+=(spaceStr+(value.bValue?"true":"false"));
                break;
            case Type::NULL_TYPE:
                outputString+=(spaceStr+"null");
                break;
            case Type::LIST:
                std::cout << "[";
                int index = 0;
                for (auto node: (*value.list)) {
                    outputString+=node->toString(indentLevel + 1);
                    if(index < (*value.list).size() - 1) {
                        outputString +=spaceStr + ", ";
                    }
                    index++;
                }
                outputString+=(spaceStr + "]\n");
                break;
            case Type::OBJECT:
                outputString+="{\n";
                for(JSONObject::iterator i = (*value.object).begin(); i!=(*value.object).end(); i++) {
                    outputString += (spaceStr + i -> first + ": ");
                    outputString += (i -> second->toString(indentLevel + 1));
                    JSONObject::iterator next = i;
                    next++;
                    if(next!=(*value.object).end()) {
                        outputString += (spaceStr + ", ");
                    }
                    outputString += (spaceStr + "\n");
                }
                outputString += "}\n";
                break;
        }
        return outputString;
    }
    void printNode(int indentLevel) {
        std::cout << toString(indentLevel);
    }
};


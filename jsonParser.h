#include "Message.h"
#include <iostream>
#include "json/nlohmann.h"
#include <string>
#ifndef _JSON_PARSER_H
#define _JSON_PARSER_H
using json = nlohmann::json;
class JsonParser
{
private:
    /* data */
public:
    JsonParser(/* args */);
    ~JsonParser();
    std::string serializeMessage(Message message);
    Message deserializeMessage(const std::string& jsonStr);
};

JsonParser::JsonParser(/* args */)
{

}

JsonParser::~JsonParser()
{
}

// 序列化函数
std::string JsonParser::serializeMessage(Message message) {
    json j;
    j["age"] = message.age;
    j["weight"] = message.weight;
    j["name"] = message.name;

    json gradesJson;
    for (const auto& grade : message.grades) {
        json gradeJson;
        gradeJson["subject"] = grade.subject;
        gradeJson["value"] = grade.value;
        gradesJson.push_back(gradeJson);
    }
    j["grades"] = gradesJson;

    return j.dump();
}

// 反序列化函数
Message JsonParser::deserializeMessage(const std::string& jsonStr) {
    json j = json::parse(jsonStr);
    Message message;
    message.age = j["age"];
    message.weight = j["weight"];
    message.name = j["name"];

    std::cout << "Age: " << message.age << std::endl;
    std::cout << "Weight: " << message.weight << std::endl;
    std::cout << "Name: " << message.name << std::endl;

    for (const auto& gradeJson : j["grades"]) {
        Grade grade;
        grade.subject = gradeJson["subject"];
        grade.value = gradeJson["value"];
        std::cout << "subject: " << grade.subject << "value: " << grade.value << std::endl;
        message.grades.push_back(grade);
    }

    return message;
}

#endif
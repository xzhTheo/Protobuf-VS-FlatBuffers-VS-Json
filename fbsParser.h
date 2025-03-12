#include "Message.h"
#include "fbsgenerate/fbsschema_generated.h"
#include <iostream>
#ifndef _FBS_PARSER_H
#define _FBS_PARSER_H
class fbsParser
{
private:
    /* data */
public:
    fbsParser(/* args */);
    ~fbsParser();
    std::string serializeMessage(Message message);
    Message deserializeMessage(std::string buffer);
};

fbsParser::fbsParser(/* args */)
{

}

fbsParser::~fbsParser()
{
}

// 序列化函数
std::string fbsParser::serializeMessage(Message message) {
    flatbuffers::FlatBufferBuilder builder;
    // 创建 grades
    std::vector<flatbuffers::Offset<fbs::grade>> fbsgrades;
    for(const auto& grade : message.grades) {
        auto fbsgrade = fbs::Creategrade(builder, builder.CreateString(grade.subject), grade.value);
        fbsgrades.push_back(fbsgrade);
    }
    auto name_offset = builder.CreateString(message.name);
    auto grades_offset = builder.CreateVector(fbsgrades);
    auto fbsmessage = fbs::CreateMessage(builder, message.age, message.weight, name_offset, grades_offset);

    builder.Finish(fbsmessage);
    auto datafbs = builder.Release();
    std::string str(reinterpret_cast<const char*>(datafbs.data()), datafbs.size());
    return str;
}

// 反序列化函数
Message fbsParser::deserializeMessage(std::string buffer) {
    auto fbsMessage = fbs::GetMessage(buffer.c_str());
    Message message;
    // std::cout << "Age: " << fbsMessage->age() << std::endl;
    // std::cout << "Weight: " << fbsMessage->weight() << std::endl;
    // std::cout << "Name: " << fbsMessage->name()->str() << std::endl;
    // message.age = fbsMessage->age();
    // message.weight = fbsMessage->weight();
    // message.name = fbsMessage->name()->str();

    // auto fbsGrades = fbsMessage->grades();
    // if (fbsGrades != nullptr) {
    //     for (const auto* fbsGrade : *fbsGrades) {
    //         Grade grade;
    //         // std::cout << "Subject: " << fbsGrade->subject()->str() << ", Value: " << fbsGrade->value() << std::endl;
    //         grade.value = fbsGrade->value();
    //         grade.subject = fbsGrade->subject()->str();
    //     }
    // }
    return message;
}

#endif
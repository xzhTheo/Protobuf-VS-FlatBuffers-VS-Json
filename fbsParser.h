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
    flatbuffers::DetachedBuffer serializeMessage(Message message);
    void deserializeMessage(const uint8_t* buffer);
};

fbsParser::fbsParser(/* args */)
{

}

fbsParser::~fbsParser()
{
}

// 序列化函数
flatbuffers::DetachedBuffer fbsParser::serializeMessage(Message message) {
    flatbuffers::FlatBufferBuilder builder;
    // 创建 grades
    std::vector<flatbuffers::Offset<fbs::grade>> fbsgrades;
    for(const auto& grade : message.grades) {
        auto fbsgrade = fbs::Creategrade(builder, builder.CreateString(grade.subject), grade.value);
        fbsgrades.push_back(fbsgrade);
    }

    // 创建 name 的偏移量
    auto name_offset = builder.CreateString(message.name);

    // 创建 grades 的向量
    auto grades_offset = builder.CreateVector(fbsgrades);

    // 创建 Message 对象
    auto fbsmessage = fbs::CreateMessage(builder, message.age, message.weight, name_offset, grades_offset);

    // 完成构建
    builder.Finish(fbsmessage);

    // 返回序列化后的数据
    return builder.Release();
}

// 反序列化函数
void fbsParser::deserializeMessage(const uint8_t* buffer) {
    auto message = fbs::GetMessage(buffer);

    std::cout << "Age: " << message->age() << std::endl;
    std::cout << "Weight: " << message->weight() << std::endl;
    std::cout << "Name: " << message->name()->str() << std::endl;

    auto grades = message->grades();
    if (grades != nullptr) {
        for (const auto* grade : *grades) {
            std::cout << "Subject: " << grade->subject()->str() << ", Value: " << grade->value() << std::endl;
        }
    }
}

#endif
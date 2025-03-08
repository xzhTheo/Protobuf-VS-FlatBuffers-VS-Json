#include <iostream>
#include <fstream>
#include <string>
#include "pbgenerate/protoSchema.pb.h"
#include "Message.h"
class pbParser {
public:
    // 序列化函数
    std::string serializeMessage(Message& msg) {
        pbmessage::Message fbmMessage;
        fbmMessage.set_age(msg.age);
        fbmMessage.set_weight(msg.weight);
        fbmMessage.set_name(msg.name);

        for(const auto& grade : msg.grades) {
            auto fbGrade = fbmMessage.add_grades();
            fbGrade->set_subject(grade.subject);
            fbGrade->set_value(grade.value);
        }
        
        std::string serialized;
        if (!fbmMessage.SerializeToString(&serialized)) {
            std::cerr << "Failed to serialize message." << std::endl;
        }
        return serialized;
    }

    // 反序列化函数
    Message deserializeMessage(std::string& serialized) {
        pbmessage::Message deserializedMessage;
        Message msg;
        deserializedMessage.ParseFromString(serialized);
        msg.age = deserializedMessage.age();
        msg.weight = deserializedMessage.weight();
        msg.name = deserializedMessage.name();
        // std::cout << " age: " << deserializedMessage.age() << std::endl;
        // std::cout << " weight: " << deserializedMessage.weight() << std::endl;
        // std::cout << " name: " << deserializedMessage.name() << std::endl;
        for (const auto& grade : deserializedMessage.grades()) {
            Grade g;
            g.subject = grade.subject();
            g.value = grade.value();
            // std::cout << "Subject: " << grade.subject() << ", Value: " << grade.value() << std::endl;
            msg.grades.push_back(g);
        }

        return msg;
    }

    // // 保存到文件
    // static bool saveToFile(const Message::Message& message, const std::string& filename) {
    //     std::fstream output(filename, std::ios::out | std::ios::binary);
    //     if (!message.SerializeToOstream(&output)) {
    //         std::cerr << "Failed to write message to file." << std::endl;
    //         return false;
    //     }
    //     return true;
    // }

    // // 从文件读取
    // static bool loadFromFile(const std::string& filename, Message::Message& message) {
    //     std::fstream input(filename, std::ios::in | std::ios::binary);
    //     if (!message.ParseFromIstream(&input)) {
    //         std::cerr << "Failed to read message from file." << std::endl;
    //         return false;
    //     }
    //     return true;
    // }
};

#include <iostream>
#include <fstream>
#include <string>
#include "pbgenerate/protoSchema.pb.h"
#include "Message.h"
class MessageSerializer {
public:
    // 序列化函数
    static std::string serialize(Message& msg;) {
        Message::Message message;
        message.set_age(msg.age);
        message.set_weight(msg.weight);
        message.set_name(msg.name);

        for(const auto& grade : msg.grades) {
            auto grade1 = message.add_grades();
            grade1->set_subject(grade.subject);
            grade1->set_value(grade.value);
        }
        auto grade1 = message.add_grades();
        grade1->set_subject("Math");
        grade1->set_value(85.0);

        auto grade2 = message.add_grades();
        grade2->set_subject("English");
        grade2->set_value(90.0);
        std::string serialized;
        if (!message.SerializeToString(&serialized)) {
            std::cerr << "Failed to serialize message." << std::endl;
        }
        return serialized;
    }

    // 反序列化函数
    static bool deserialize(const std::string& serialized, Message::Message& message) {
        return message.ParseFromString(serialized);
    }

    // 保存到文件
    static bool saveToFile(const Message::Message& message, const std::string& filename) {
        std::fstream output(filename, std::ios::out | std::ios::binary);
        if (!message.SerializeToOstream(&output)) {
            std::cerr << "Failed to write message to file." << std::endl;
            return false;
        }
        return true;
    }

    // 从文件读取
    static bool loadFromFile(const std::string& filename, Message::Message& message) {
        std::fstream input(filename, std::ios::in | std::ios::binary);
        if (!message.ParseFromIstream(&input)) {
            std::cerr << "Failed to read message from file." << std::endl;
            return false;
        }
        return true;
    }
};

int main() {

    // 序列化
    std::string serialized = MessageSerializer::serialize(message);
    std::cout << "Serialized size: " << serialized.size() << " bytes" << std::endl;

    // 反序列化
    Message::Message deserializedMessage;
    if (MessageSerializer::deserialize(serialized, deserializedMessage)) {
        std::cout << "Deserialized age: " << deserializedMessage.age() << std::endl;
        std::cout << "Deserialized weight: " << deserializedMessage.weight() << std::endl;
        std::cout << "Deserialized name: " << deserializedMessage.name() << std::endl;
        for (const auto& grade : deserializedMessage.grades()) {
            std::cout << "Subject: " << grade.subject() << ", Value: " << grade.value() << std::endl;
        }
    }

    // 保存到文件
    std::string filename = "message.bin";
    if (MessageSerializer::saveToFile(message, filename)) {
        std::cout << "Message saved to " << filename << std::endl;
    }

    // 从文件读取
    Message::Message loadedMessage;
    if (MessageSerializer::loadFromFile(filename, loadedMessage)) {
        std::cout << "Message loaded from " << filename << std::endl;
        std::cout << "Loaded age: " << loadedMessage.age() << std::endl;
        std::cout << "Loaded weight: " << loadedMessage.weight() << std::endl;
        std::cout << "Loaded name: " << loadedMessage.name() << std::endl;
        for (const auto& grade : loadedMessage.grades()) {
            std::cout << "Subject: " << grade.subject() << ", Value: " << grade.value() << std::endl;
        }
    }

    return 0;
}
#include <string>
#include <vector>
#ifndef _MESSAGE_H
#define _MESSAGE_H
//非扁平化（多层键值对结构）数据测试
class Grade
{
public:
    Grade() : subject(""), value(0) {}
    ~Grade() {
        subject = "";
        value = 0;
    }
public:
    std::string subject;
    float value;
};

class Message
{
public:
    Message() : age(0), weight(0), name("") {
        grades.clear();
    }
    ~Message() {
        age = 0;
        weight = 0;
        name = "";
        grades.clear();
    }
public:
    int age;
    float weight;
    std::string name;
    std::vector<Grade> grades;
};

#endif
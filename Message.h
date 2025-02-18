#include <string>
#include <vector>
class grade
{
public:
    grade() : subject(""), value(0) {}
    ~grade() {
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
    std::vector<grade> grades;
};
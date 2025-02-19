#include <iostream>
#include "Message.h"
#include "fbsParser.h"
void initMessage(Message& msg)
{
    msg.age = 19;
    msg.name = "ppp";

    Grade grade;
    grade.subject = "Math";
    grade.value = 100;
    msg.grades.push_back(grade); 

    grade.subject = "English";
    grade.value = 90;
    msg.grades.push_back(grade);
}
int main()
{
    Message msg;
    initMessage(msg);
    fbsParser parser;
    return 0;
}
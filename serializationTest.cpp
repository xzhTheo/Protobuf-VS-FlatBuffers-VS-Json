#include <iostream>
#include "Message.h"
#include "fbsParser.h"
#include "jsonParser.h"
#include "fbsgenerate/fbsschema_generated.h"
#include <string>
void initMessage(Message& msg)
{
    msg.age = 19;
    msg.name = "ppp";
    msg.weight = 60.0f;

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
    // --------------------------fbsParser--------------------------
    // fbsParser parser;
    // flatbuffers::DetachedBuffer detachedBuffer = parser.serializeMessage(msg);
    // auto fbsBuffer = detachedBuffer.data();
    // parser.deserializeMessage(fbsBuffer);
    // --------------------------fbsParser--------------------------
    
    // --------------------------jsonParser--------------------------
    JsonParser jsonParser;
    std::string jsonBuffer = jsonParser.serializeMessage(msg);
    Message jmsg = jsonParser.deserializeMessage(jsonBuffer);
    // --------------------------jsonParser--------------------------
    return 0;
}
#include <iostream>
#include "Message.h"
#include "fbsParser.h"
#include "jsonParser.h"
#include "pbParser.h"
#include "fbsgenerate/fbsschema_generated.h"
#include <string>
#include <fstream>
#include <thread>
#include <chrono>

#define MAX_WRITE_TIMES 1000000
#define MAX_SERIALIZE_TIMES 1000000
#define MAX_DESERIALIZE_TIMES 1000000

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

void fbsfunc(Message msg)
{
    // memory compare---------------------------------
    auto memoryCompareFunc = [msg]()mutable{
        std::ofstream binOut("fbsdata.bin");
        if (binOut) {
            fbsParser parser;
            std::string serializedStr = parser.serializeMessage(msg);
            // parser.deserializeMessage(fbsBuffer);
            for(int i = 0; i < MAX_WRITE_TIMES ;i++)
            {
                binOut.write(serializedStr.c_str(), serializedStr.size());
            }
            std::cout << "fbs size: "<< binOut.tellp()/1024 << "KB"  <<std::endl;
            binOut.close();
        }
    };

    // serialize speed compare---------------------------------
    auto serializeSpeedCompareFunc = [msg](){
        fbsParser parser;
        auto start = std::chrono::system_clock::now();
        for(int i = 0; i < MAX_SERIALIZE_TIMES ;i++)
        {
            std::string serializedStr = parser.serializeMessage(msg);
        }
        auto end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "fbs serialize time :" << duration << " ms"<<std::endl;
    };

    // serialize speed compare---------------------------------
    auto deserializeSpeedCompareFunc = [msg](){
        fbsParser parser;
        std::string serializedStr = parser.serializeMessage(msg);
        auto start = std::chrono::system_clock::now();
        for(int i = 0; i < MAX_SERIALIZE_TIMES ;i++)
        {
            Message deserializeMsg = parser.deserializeMessage(serializedStr);
        }
        auto end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "fbs deserialize time: " << duration << "ms" <<std::endl;
    };
    memoryCompareFunc();
    serializeSpeedCompareFunc();
    deserializeSpeedCompareFunc();
}

void jsonfunc(Message msg)
{
    // memory compare---------------------------------
    auto memoryCompareFunc = [msg]()mutable{
        std::ofstream binOut("jsondata.bin");
        if (binOut) {
            JsonParser jsonParser;
            std::string serializedStr = jsonParser.serializeMessage(msg);
            // Message jmsg = jsonParser.deserializeMessage(jsonBuffer);
            for(int i = 0 ; i < MAX_WRITE_TIMES ;i++)
            {
                binOut.write(serializedStr.c_str(), serializedStr.size());
            }
            std::cout << "json size: "<< binOut.tellp()/1024 << "KB"  <<std::endl;
            binOut.close();
        }
    };

    // serialize speed compare---------------------------------
    auto serializeSpeedCompareFunc = [msg](){
        JsonParser jsonParser;
        auto start = std::chrono::system_clock::now();
        for(int i = 0; i < MAX_SERIALIZE_TIMES ;i++)
        {
            std::string serializedStr = jsonParser.serializeMessage(msg);
        }
        auto end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "json serialize time :" << duration << " ms" <<std::endl;
    };

    // serialize speed compare---------------------------------
    auto deserializeSpeedCompareFunc = [msg](){
        JsonParser jsonParser;
        std::string serializedStr = jsonParser.serializeMessage(msg);
        auto start = std::chrono::system_clock::now();
        for(int i = 0; i < MAX_SERIALIZE_TIMES ;i++)
        {
            Message deserializeMsg = jsonParser.deserializeMessage(serializedStr);
        }
        auto end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "json deserialize time: " << duration << "ms" <<std::endl;
    };
    memoryCompareFunc();
    serializeSpeedCompareFunc();
    deserializeSpeedCompareFunc();
}

void pbfunc(Message msg)
{
    // memory compare---------------------------------
    auto memoryCompareFunc = [msg]()mutable{
        std::ofstream binOut("pbdata.bin");
        if (binOut) {
            pbParser pbparser;
            std::string serializedStr = pbparser.serializeMessage(msg);
            // Message pbmsg = pbparser.deserializeMessage(pbBuffer);
            for(int i = 0; i < MAX_WRITE_TIMES ;i++)
            {
                binOut.write(serializedStr.c_str(), serializedStr.size());
            }
            std::cout << "pb size: "<< binOut.tellp() /1024 << "KB" <<std::endl;
            binOut.close();
        }
    };

    // serialize speed compare---------------------------------
    auto serializeSpeedCompareFunc = [msg]()mutable{
        pbParser pbparser;
        auto start = std::chrono::system_clock::now();
        for(int i = 0; i < MAX_SERIALIZE_TIMES ;i++)
        {
            std::string serializedStr = pbparser.serializeMessage(msg);
        }
        auto end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "pb serialize time: " << duration << "ms" <<std::endl;
    };

    // serialize speed compare---------------------------------

    auto deserializeSpeedCompareFunc = [msg]()mutable{
        pbParser pbparser;
        std::string serializedStr = pbparser.serializeMessage(msg);
        auto start = std::chrono::system_clock::now();
        for(int i = 0; i < MAX_SERIALIZE_TIMES ;i++)
        {
            Message deserializeMsg = pbparser.deserializeMessage(serializedStr);
        }
        auto end = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "pb deserialize time: " << duration << "ms" <<std::endl;
    };
    memoryCompareFunc();
    serializeSpeedCompareFunc();
    deserializeSpeedCompareFunc();

}

int main()
{
    Message msg;
    initMessage(msg);
    
    std::thread fbsfuncth(fbsfunc, msg);
    std::thread jsonfuncth(jsonfunc, msg);
    std::thread pbfuncth(pbfunc, msg);

    fbsfuncth.join();
    jsonfuncth.join();
    pbfuncth.join();

    return 0;
}
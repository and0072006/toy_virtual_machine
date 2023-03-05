#pragma once

#include <string>
#include <CommonType.h>
#include <unordered_map>

struct Parameters
{
    int    time;
    int    port;
    std::string ipAddr;
    std::string logFile;
    bool   allowLogging;
    int    maxClients;
    int    logLevel;
};

struct T_MSG
{
    int value;
    char msg[5];
};


static Command get_command_type(const std::string &name)
{
    static std::unordered_map<std::string, Command> map = {{"ADD", Command::ADD},
                                                           {"DIV", Command::DIV},
                                                           {"MOV", Command::MOV},
                                                           {"MUL", Command::MUL},
                                                           {"SUB", Command::SUB}};
    return map[name];
}


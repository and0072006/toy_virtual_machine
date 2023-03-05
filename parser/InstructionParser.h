#pragma once

#include <string>
#include <vector>

#include "InstructionDetector.h"
#include "CommonType.h"



class InstructionParser
{
public:
    InstructionParser();
    ~InstructionParser();

    Instructions parse(const std::string &file);
private:
    InstructionDetector _detector;
};

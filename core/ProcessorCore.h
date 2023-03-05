#pragma once

#include "Registers.h"

class ProcessorCore
{
public:
    ProcessorCore();
    ~ProcessorCore();

private:
    Registers _registers;

};

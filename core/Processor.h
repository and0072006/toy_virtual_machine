#pragma once

#include "ProcessorCore.h"

#include <vector>

class Processor
{
public:
    Processor();
    ~Processor();

private:
    std::vector<ProcessorCore> _cores;

};

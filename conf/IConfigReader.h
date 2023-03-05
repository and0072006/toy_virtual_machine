#pragma once

#include <string>
#include "Util.h"


class IConfigReader
{
public:
    virtual ~IConfigReader() = default;

    virtual bool ReadConfig(const std::string& file, Parameters* pParam) = 0;
};

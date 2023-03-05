#pragma once

#include "IConfigReader.h"
#include <iostream>
#include <map>
#include <fstream>

class TxtConfigReader: public IConfigReader
{
private:
    std::map<std::string,std::string> m_data;

    bool init(const std::string& file);
public:

    virtual bool ReadConfig(const std::string& file, Parameters* param);
};

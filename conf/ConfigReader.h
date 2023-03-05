#pragma once

#include "IConfigReader.h"
#include "TxtConfigReader.h"
#include <memory>


class ConfigReader: public IConfigReader
{
private:
    IConfigReader* m_pReader;

public:
    ConfigReader(IConfigReader* pReader): m_pReader(pReader){};
    ~ConfigReader(){delete m_pReader;};

    bool ReadConfig(const std::string& file, Parameters* pParam);
};

typedef std::shared_ptr<ConfigReader> ConfigReaderPtr;

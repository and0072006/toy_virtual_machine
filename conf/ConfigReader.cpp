#include "ConfigReader.h"


bool ConfigReader::ReadConfig(const std::string& file, Parameters* pParam)
{
    return m_pReader->ReadConfig(file, pParam);
}
